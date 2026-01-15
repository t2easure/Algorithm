#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int V;
vector<vector<pair<int, int>>> graph;

pair<int, int> dfs(int start) {
    vector <int> visited(V + 1, 0);
    visited[start] = 1;
    stack <pair<int, int>> s;   
    s.push({start, 0});

    pair<int, int> farthest = {start, 0};
    while (!s.empty()) {
        int current = s.top().first;
        int distance = s.top().second;
        s.pop();

        if (distance > farthest.second) farthest = {current, distance};

        for (int i = 0; i < graph[current].size(); i++) {
            int adj = graph[current][i].first;
            int cost = graph[current][i].second;

            if (!visited[adj]) {
                visited[adj] = 1;
                s.push({adj, distance + cost});
            }
        }
    }
    return farthest;
}

int main() {
    cin >> V;
    graph.resize(V + 1);
    for (int i = 0; i < V; i++) {
        int num, a, b;
        cin >> num >> a;
        while (a != -1) {
            cin >> b;
            graph[a].push_back({num, b});
            graph[num].push_back({a, b});
            cin >> a;
        }
    }

    pair<int, int> nodeA = dfs(1);
    pair<int, int> nodeB = dfs(nodeA.first);
    cout << nodeB.second;

    return 0;
}