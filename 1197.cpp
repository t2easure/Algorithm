#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int V, E;
vector<int> parent;

int find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}

void union_set(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if (x != y) parent[y] = x;
}

int main() {
    cin >> V >> E;
    parent.resize(V + 1);
    for (int i = 1; i <= V; i++) parent[i] = i;

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    vector<pair<int, pair<int, int>>> MST;

    for (int i = 0; i < edges.size(); i++) {
        pair<int, pair<int, int>> cur_edge = edges[i];

        int v1 = cur_edge.second.first;
        int v2 = cur_edge.second.second;

        if (find_parent(v1) == find_parent(v2)) continue;

        MST.push_back(cur_edge);
        union_set(v1, v2);

        if (MST.size() == V - 1) break;
    }

    int cost = 0;
    for (int i = 0; i < MST.size(); i++) cost += MST[i].first;

    cout << cost;
    return 0;
}