#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    if (n <= 1) {
        cout << dp[n] << endl;
        return 0;
    }

    dp[2] = 2;

    if (n <= 2) {
        cout << dp[n] << endl;
        return 0;
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cout << dp[n] << endl;
    return 0;
}