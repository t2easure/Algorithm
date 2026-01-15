#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map <long long, long long> dp;

long long solve (long long N, long long P, long long Q, long long X, long long Y) {
    if (N <= 0) return 1;
    if (dp.count(N)) return dp[N];

    long long a = solve (N / P - X, P, Q, X, Y);
    long long b = solve (N / Q - Y, P, Q, X, Y);

    return dp[N] = a + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, P, Q, X, Y;
    cin >> N >> P >> Q >> X >> Y;

    cout << solve(N, P, Q, X, Y);
    return 0;
}