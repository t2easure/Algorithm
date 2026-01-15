#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            int current = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if (distance > dist[i][current]) continue;

            for (int j = 0; j < graph[current].size(); j++) {
                int vertex = graph[current][j].first;
                int cost = graph[current][j].second;

                if (dist[i][vertex] > dist[i][current] + cost) {
                    dist[i][vertex] = dist[i][current] + cost;
                    pq.push({dist[i][vertex], vertex});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == numeric_limits<int>::max()) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}