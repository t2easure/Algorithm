#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector <int> dp(str.length() + 1, 0);
    if (str[0] != '0') {
        dp[0] = 1;
    } 

    if (str.length() == 1) {
        cout << dp[0] << endl;
        return 0;
    }

    for (int i = 1; i < str.length(); i++) {
        if (str[i] != '0') {
            dp[i] = (dp[i] + dp[i - 1]) % 1000000;
        }

        int two = (str[i - 1] - '0') * 10 + str[i] - '0';
        if (two >= 10 && two <= 26) {
            if (i == 1) dp[i] = (1 + dp[i]) % 1000000;
            else dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
    }

    cout << dp[str.length() - 1] << endl;
    return 0;
}