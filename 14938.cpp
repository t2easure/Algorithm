#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> items(n + 1);
    for (int i = 1; i <= n; i++) cin >> items[i];
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int max_items = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> dist(n + 1, INF);
        dist[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});

        while (!pq.empty()) {
            int current = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if (distance > dist[current]) continue;

            for (int j = 0; j < graph[current].size(); j++) {
                int vertex = graph[current][j].first;
                int cost = graph[current][j].second;

                if (dist[vertex] > dist[current] + cost) {
                    dist[vertex] = dist[current] + cost;
                    pq.push({dist[vertex], vertex});
                }
            }
        }

        int total_items = 0;

        for (int j = 1; j <= n; j++) {
            if (dist[j] <= m) total_items += items[j];
        }

        max_items = max(total_items, max_items);
    }

    cout << max_items << endl;

    return 0;
}