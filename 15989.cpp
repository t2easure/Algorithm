#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector <int> dp(10000, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        for (int j = 4; j <= n; j ++) 
            dp[j] = dp[j - 3] + j / 2 + 1;
        cout << dp[n] << endl;
    }

    return 0;
}