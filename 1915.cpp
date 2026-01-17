#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int array[n][m];
    int dp[n][m];

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++) {
            array[i][j] = str[j] - '0';
            dp[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                if (array[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (max < dp[i][j]) max = dp[i][j];
        }
    }

    cout << max * max << endl;
    return 0;
}