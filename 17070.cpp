#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> grid(N + 1, vector<int>(N + 1));
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(3, 0)));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    dp[1][2][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            if (grid[i][j] == 1) continue;

            if (j - 1 >= 1 && grid[i][j - 1] == 0) dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
            if (i - 1 >= 1 && grid[i - 1][j] == 0) dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
            if (i - 1 >= 1 && j - 1 >= 1 && grid[i][j - 1] == 0 && grid[i - 1][j] == 0 && grid[i - 1][j - 1] == 0) dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }

    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << "\n";
    return 0;
}