#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector <int> dp(N + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

    int ans = 1;
    int prev_vip = 0;

    for (int i = 0; i < M; i++) {
        int current_vip;
        cin >> current_vip;

        int length = current_vip - 1 - prev_vip;
        ans *= dp[length];

        prev_vip = current_vip;
    }

    ans *= dp[N - prev_vip];

    cout << ans << endl;
 
    return 0;
}