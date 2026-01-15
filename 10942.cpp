#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector <int> number(N + 1);
    
    for (int i = 1; i <= N; i++) cin >> number[i];
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) dp[i][i] = 1;
    for (int i = 1; i < N; i++) {
        if (number[i] == number[i + 1]) dp[i][i + 1] = 1;
    }

    for (int i = 3; i <= N; i++) {
        for (int j = 1; j + i - 1 <= N; j++) {
            int end = j + i - 1;
            if (number[end] == number[j] && dp[j + 1][end - 1]) dp[j][end] = 1;
        }
    }

    int M;
    cin >> M;
    while (M --) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }

    return 0;
}