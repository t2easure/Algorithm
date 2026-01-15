#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end()); // A를 오름차순으로 정리

    vector <int> dp(n, 1);
    int max_keep = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second) dp[i] = max(dp[i], dp[j] + 1);
        }
        if (dp[i] > max_keep) max_keep = dp[i];
    }

    cout << n - max_keep << endl;

    return 0;
}