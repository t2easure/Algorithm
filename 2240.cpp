#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, W;
    cin >> T >> W;

    vector <int> current (T + 1);
    vector <vector<int>> dp(T + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= T; i++) cin >> current[i];

    if (current[1] == 1) {
        dp[1][0] = 1;
    } else {
        dp[1][0] = 0;
    }

    if (current[1] == 2) {
        dp[1][1] = 1;
    } else {
        dp[1][1] = 0;
    }

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            int pos = (j % 2 == 0) ? 1 : 2;
            int get_plum = (pos == current[i]) ? 1 : 0;

            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + get_plum;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + get_plum;
            }
        }
    }

    cout << *max_element(dp[T].begin(), dp[T].end());

    return 0;
}