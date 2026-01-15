#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector <pair<int, int>> backpack(N);

    for (int i = 0; i < N; i++) {
        cin >> backpack[i].first >> backpack[i].second;
    }

    vector <vector<int>> dp(N + 1, vector<int> (K + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= K; w++) {
            if (backpack[i - 1].first <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - backpack[i - 1].first] + backpack[i - 1].second);
            } else dp[i][w] = dp[i - 1][w];
        }
    }

    cout << dp[N][K];

    return 0;
}