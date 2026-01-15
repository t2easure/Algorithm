#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector <vector<pair<int, int>>> graph(V + 1);
    
    int start;
    cin >> start;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector <int> dist(V + 1, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (distance > dist[current]) continue;

        for (int i = 0; i < graph[current].size(); i++) {
            int vertex = graph[current][i].first;
            int cost = graph[current][i].second;

            if (dist[vertex] > dist[current] + cost) {
                dist[vertex] = dist[current] + cost;
                pq.push({dist[vertex], vertex});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] != numeric_limits<int>::max()) cout << dist[i] << endl;
        else cout << "INF" << endl;
    }

    return 0;
}