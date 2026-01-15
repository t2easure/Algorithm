#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    int N;
    cin >> N;
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            long long distance;
            cin >> distance;
            if (i != j && i <= j) edges.push_back({distance, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    vector<pair<long long, pair<int, int>>> MST;
    for (int i = 0; i < edges.size(); i++) {
        pair<long long, pair<int, int>> cur_edge = edges[i];

        int v1 = cur_edge.second.first;
        int v2 = cur_edge.second.second;

        if (find_root(v1) == find_root(v2)) continue;

        union_set(v1, v2);
        MST.push_back(cur_edge);

        if (MST.size() == N - 1) break;
    }

    long long cost = 0;
    for (int i = 0; i < MST.size(); i++) cost += MST[i].first;

    cout << cost;
    return 0;
}