#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector <vector<int>> sticker(2, vector<int>(n));
        for (int j = 0; j < 2; j++) {
            for (int a = 0; a < n; a++) cin >> sticker[j][a];
        }
        
        if (n == 1) {
            cout << max(sticker[0][0], sticker[1][0]) << endl;
            continue;
        }

        vector <vector<int>> dp(2, vector<int>(n));
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = sticker[1][0] + sticker[0][1];
        dp[1][1] = sticker[0][0] + sticker[1][1];

        for (int j = 2; j < n; j++) {
            dp[0][j] = max(dp[1][j - 1], max(dp[0][j - 2], dp[1][j - 2])) + sticker[0][j];
            dp[1][j] = max(dp[0][j - 1], max(dp[0][j - 2], dp[1][j - 2])) + sticker[1][j];
        }

        cout << max(dp[1][n - 1], dp[0][n - 1]) << endl;
    }

    return 0;
}