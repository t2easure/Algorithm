#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <string>

using namespace std;

#define INF numeric_limits<int>::max()

string bellmanFord(int src, int N, vector<vector<pair<int, int>>> &graph) {
    vector<int> dist(N + 1, INF);
    dist[src] = 0;

    bool updated;
    for (int i = 0; i < N; i++) {
        updated = false;
        for (int j = 1; j <= N; j++) {
            if (dist[j] == INF) continue;
            for (int a = 0; a < graph[j].size(); a++) {
                int v = graph[j][a].first;
                int cost = graph[j][a].second;

                if (dist[v] > dist[j] + cost) {
                    dist[v] = dist[j] + cost;
                    updated = true;
                    if (i == N - 1) return "YES";
                }
            }
        }
        if (!updated) break;
    }

    if (updated) {
        for (int i = 1; i <= N; i++) {
            if (dist[i == INF]) continue;
            for (int j = 0; j < graph[i].size(); j++) {
                int v = graph[i][j].first;
                int cost = graph[i][j].second;

                if (dist[v] > dist[j] + cost) {
                    return "YES";
                }
            }
        }
    }

    return "NO";
}

int main() {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<vector<pair<int, int>>> graph(N + 1);

        for (int j = 0; j < M; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            graph[S].push_back({E, T});
            graph[E].push_back({S, T});
        }

        for (int j = 0; j < W; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            graph[S].push_back({E, -T});
        }

        string result = "NO";
        for (int i = 1; i <= N; i++) {
            result = bellmanFord(i, N, graph);
            if (result == "YES") break;
        }

        cout << result << "\n";
    }

    return 0;
}