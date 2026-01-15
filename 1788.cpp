#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int N = abs(n);

    if (N == 0) cout << 0 << endl;
    else if (n < 0 && N % 2 == 0) cout << -1 << endl;
    else cout << 1 << endl;

    vector <long long> dp(N + 1);
    dp[0] = 0;
    if (N > 0) dp[1] = 1;
    for (int i = 2; i <= N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;

    cout << dp[N] << endl;
    return 0;
}