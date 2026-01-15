#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool Bipartite(vector<vector<int>> &graph, vector<int>& visited, int start) {
    queue <int> q; 
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            if (visited[graph[current][i]] == -1) {
                visited[graph[current][i]] = 1 - visited[current];
                q.push(graph[current][i]);
            } else if (visited[graph[current][i]] == visited[current]) return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int V, E;
        cin >> V >> E;

        vector <vector<int>> graph(V);
        vector <int> visited(V, -1);

        for (int j = 0; j < E; j++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1].push_back(b -1);
            graph[b - 1].push_back(a -1);
        }

        bool isbipartite = true;

        for (int i = 0; i < V; i++) {
            if (visited[i] == -1) {
                if (!Bipartite(graph, visited, i)) {
                    isbipartite = false;
                    break;
                }
            }
        }

        if (isbipartite) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}