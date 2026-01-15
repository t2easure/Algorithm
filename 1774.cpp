#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

vector <int> parent;

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);
}

void union_set(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) parent[y] = x;
}

double distance(pair<int, int> a, pair<int, int> b) {
    return pow(pow((a.first - b.first), 2) + pow((a.second - b.second), 2), 0.5);
}

int main() {
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;
    vector<pair<int, int>> gods(N + 1);
    for (int i = 1; i <= N; i++) cin >> gods[i].first >> gods[i].second;
    vector<pair<double, pair<int, int>>> edges;

    vector<pair<double, pair<int, int>>> MST;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (find_root(i) != find_root(j)) {
                edges.push_back({distance(gods[i], gods[j]), {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        pair<double, pair<int, int>> cur_edge = edges[i];

        int v1 = cur_edge.second.first;
        int v2 = cur_edge.second.second;

        if (find_root(v1) == find_root(v2)) continue;

        MST.push_back(cur_edge);
        union_set(v1, v2);

        if (MST.size() == N - 1) break;
    }

    double cost = 0;
    for (int i = 0; i < MST.size(); i++) cost += MST[i].first;

    cout << fixed << setprecision(2) << cost << "\n";

    return 0;
}