#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> classes(N);
    for (int i = 0; i < N; i++) cin >> classes[i].first >> classes[i].second;

    sort(classes.begin(), classes.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(classes[0].second);

    for (int i = 1; i < N; i++) {
        if (pq.top() <= classes[i].first) pq.pop();
        pq.push(classes[i].second);
    }

    cout << pq.size() << "\n";

    return 0;
}