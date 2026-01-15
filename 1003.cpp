#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> addPairs(const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

int main() {
    int T;
    cin >> T;

    vector<pair<int, int>> dp(41, make_pair(0, 0));
    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);

    for (int i = 2; i <= 40; i++)
        dp[i] = addPairs(dp[i - 1], dp[i - 2]);

    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        cout << dp[num].first << " " << dp[num].second << endl;
    }

    return 0;
}