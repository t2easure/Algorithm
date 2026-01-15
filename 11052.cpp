#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> cards(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> cards[i];
    }

    vector <int> dp(N + 1);
    dp[0] = 0;
    dp[1] = cards[1];

    if (N == 1) {
        cout << cards[1] << endl;
        return 0;
    }

    dp[2] = max(cards[2], 2 * cards[1]);
    if (N == 2) {
        cout << dp[2] << endl;
        return 0;
    }

    for (int i = 3; i <= N; i++) { 
        int max_value = cards[i];
        for (int j = 1; j <= (i - 1); j ++) {
            if (max_value < dp[j] + dp[i - j]) {
                max_value = dp[j] + dp[i - j];
            }
        }
        dp[i] = max_value;
    }

    cout << dp[N] << endl;

    return 0;
}