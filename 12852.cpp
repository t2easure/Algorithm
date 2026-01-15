#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector <pair<long long, long long>> dp(N + 1, {0, 0});
    dp[1] = {0, 1};

    if (N == 1) {
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }

    dp[2] = {1, 1};
    if (N == 2) {
        cout << 1 << endl;
        cout << N << " " << 1 << endl;
        return 0;
    }

    dp[3] = {1, 1};
    if (N == 3) {
        cout << 1 << endl;
        cout << N << " " << 1 << endl;
        return 0;
    }

    for (long long i = 4; i <= N; i++) {
        dp[i].first = dp[i - 1].first + 1;
        dp[i].second = i - 1;

        if (i % 3 == 0) {
            if (dp[i].first > dp[i / 3].first + 1) {
                dp[i].first = dp[i / 3].first + 1;
                dp[i].second = i / 3;
            }
        }

        if (i % 2 == 0) {
            if (dp[i].first > dp[i / 2].first + 1) {
                dp[i].first = dp[i / 2].first + 1;
                dp[i].second = i / 2;
            }
        }
    }

    cout << dp[N].first  << endl;
    while (N > 1) {
        cout << N << " ";
        N = dp[N].second;
    }
    cout << 1 << endl;

    return 0;
}