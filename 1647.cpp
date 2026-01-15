#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> parent; 

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);
}

void union_set(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) parent[y] = x;
}

int main() {
    cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    vector<pair<int, pair<int, int>>> MST;
    for (int i = 0; i < M; i++) {
        pair<int, pair<int, int>> cur_edge = edges[i];

        int v1 = cur_edge.second.first;
        int v2 = cur_edge.second.second;

        if (find_root(v1) == find_root(v2)) continue;

        union_set(v1, v2);
        MST.push_back(cur_edge);

        if (MST.size() == N - 1) break;
    }

    int cost = 0;
    for (int i = 0; i < MST.size() - 1; i++) cost += MST[i].first;

    cout << cost << "\n";
    return 0;
}