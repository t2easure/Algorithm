#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 0));
    dp[0][0] = 1;

    for (int k = 1; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            dp[k][n] = dp[k-1][n]; 
            if (n > 0)
                dp[k][n] = (dp[k][n] + dp[k][n-1]) % 1000000000;
        }
    }

    cout << dp[K][N] << endl;
    return 0;
}