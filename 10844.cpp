#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

    for (int i = 1; i <= 9; i++) dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) dp[i][0] = dp[i - 1][1];
            else if (j == 9) dp[i][9] = dp[i - 1][8];
            else dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
            dp[i][j] %= 1000000000;
        } 
    }
    
    long long result = 0;
    for (int i = 0; i <= 9; i++) result = (result + dp[N][i]) % 1000000000;

    cout << result << endl;
    return 0;
}