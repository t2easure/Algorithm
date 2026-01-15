#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> amount(n + 1);
    for (int i = 1; i <= n; i++) { 
        cin >> amount[i];
    }

    amount[0] = 0;

    vector <int> dp(n + 1);
    dp[0] = 0;
    dp[1] = amount[1];
    if (n == 1) {
        cout << amount[1] << endl;
        return 0;
    }
    else if (n == 2) {
        cout << amount[2] + amount[1] << endl;
        return 0;
    }
    dp[2] = amount[2] + amount[1];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + amount[i], dp[i - 3] + amount[i - 1] + amount[i]));
    }

    cout << dp[n] << endl;

    return 0;
}