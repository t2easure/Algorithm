#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first < b.first;
}

int main() {
    int N;
    cin >> N;

    vector <pair<long long, long long>> meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings.begin(), meetings.end(), compare);

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    minHeap.push(meetings[0].second);

    for (int i = 1; i < N; i++) {
        if (meetings[i].first >= minHeap.top()) {
            minHeap.pop();
        }
        minHeap.push(meetings[i].second);
    }

    cout << minHeap.size();

    return 0;
}