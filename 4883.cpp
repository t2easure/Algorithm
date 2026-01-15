#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;

    while (n >= 0) {
        int N;
        cin >> N;
        if (N == 0) break;

        n += 1;
        int dp[N + 1][4];
        int map[N + 1][4];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> map[i][j];
            }
        }

        dp[1][1] = 1e9;
        dp[1][2] = map[1][2];
        dp[1][3] = map[1][2] + map[1][3];

        for (int i = 2; i <= N; i++) {
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][1];
            dp[i][2] = min(dp[i - 1][1], min(dp[i - 1][2], min(dp[i - 1][3], dp[i][1]))) + map[i][2];
            dp[i][3] = min(dp[i - 1][2], min(dp[i - 1][3], dp[i][2])) + map[i][3];
        }

        cout << n << ". " << dp[N][2] << endl;
    }
}