#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> parent;

int find_root(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void union_set(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) parent[y] = x;
}

int main() {
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    long long all = 0;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
        all += c;
    }

    sort(edges.begin(), edges.end());

    vector<pair<int, pair<int, int>>> MST;
    for (int i = 0; i < edges.size(); i++) {
        pair<int, pair<int, int>> current = edges[i];

        int v1 = current.second.first;
        int v2 = current.second.second;

        if (find_root(v1) == find_root(v2)) continue;

        union_set(v1, v2);
        MST.push_back(current);

        if (MST.size() == N - 1) break;
    }
    
    if (MST.size() != N - 1) {
        cout << -1 << "\n";
        return 0;
    }

    long long cost = 0;
    for (int i = 0; i < MST.size(); i++) cost += MST[i].first;

    cout << all - cost << "\n";

    return 0;
}