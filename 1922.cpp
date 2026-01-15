#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
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
    cin >> N >> M;
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    vector <pair<int, pair<int, int>>> edges;

    for (int i = 0; i < M; i++) {
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

        union_set(v1, v2);
        MST.push_back(cur_edge);
    }

    int cost = 0;
    for (int i = 0; i < MST.size(); i++) cost += MST[i].first;

    cout << cost << endl;
    return 0;
}