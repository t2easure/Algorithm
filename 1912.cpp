#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> number(n + 1);
    vector <int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> number[i];
    }

    dp[1] = number[1];
    if (n == 1) {
        cout << dp[1];

        return 0;
    }
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] + number[i], number[i]);
    }

    cout << *max_element(dp.begin() + 1, dp.end());
    return 0;
}