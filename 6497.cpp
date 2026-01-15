#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

int find_root(int x, vector<int> &parent) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x], parent);
}

void union_set(int x, int y, vector<int> &parent) {
    x = find_root(x, parent);
    y = find_root(y, parent);

    if (x != y) parent[y] = x;
}

int main() {
    cin >> m >> n;
    while (m != 0 && n != 0) {
        int all = 0;
        vector <int> parent(m + 1);
        for (int i = 1; i <= m; i++) parent[i] = i;

        vector <pair<int, pair<int, int>>> edges;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            all += z;
            edges.push_back({z, {x, y}});
        }

        sort(edges.begin(), edges.end());

        vector <pair<int, pair<int, int>>> MST;
        for (int i = 0; i < edges.size(); i++) {
            pair<int, pair<int, int>> cur_edge = edges[i];

            int v1 = cur_edge.second.first;
            int v2 = cur_edge.second.second;

            if (find_root(v1, parent) == find_root(v2, parent)) continue;

            union_set(v1, v2, parent);
            MST.push_back(cur_edge);

            if (MST.size() == m - 1) break;
        }

        int cost = 0;
        for (int i = 0; i < MST.size(); i++) cost += MST[i].first;

        cout << all - cost << "\n";

        cin >> m >> n;
    }

    return 0;
}