#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector <vector<pair<int, int>>> graph(N + 1); 

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end;

    vector<int> dist(N + 1, numeric_limits<int>::max());
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

    cout << dist[end] << endl;

    return 0;    
}