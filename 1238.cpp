#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, numeric_limits<int>::max()));
    for (int i = 1; i <= N; i++) {
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

    vector<int> result(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        result[i] = dist[i][X] + dist[X][i];
    }

    cout << *max_element(result.begin(), result.end());

    return 0;
}