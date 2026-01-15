#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> parent;

pair<int, int> find_root(pair<int, int> x) {
    if (parent[x.first][x.second] == x) return x;
    return parent[x.first][x.second] = find_root(parent[x.first][x.second]);
}

void union_set(pair<int, int> x, pair<int, int> y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) parent[y.first][y.second] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int R, C;
        cin >> R >> C;

        parent.clear();
        parent.resize(R + 1, vector<pair<int, int>>(C + 1));
        for (int j = 1; j <= R; j++) {
            for (int a = 1; a <= C; a++) {
                parent[j][a] = {j, a};
            }
        }

        vector<pair<int, pair<pair<int, int>, pair<int, int>>>> edges;
        for (int a = 1; a <= R; a++) {
            for (int b = 1; b <= C - 1; b++) {
                int cost; 
                cin >> cost;
                edges.push_back({cost, {{a, b}, {a, b + 1}}});
            }
        }

        for (int a = 1; a <= R - 1; a++) {
            for (int b = 1; b <= C; b++) {
                int cost;
                cin >> cost;
                edges.push_back({cost, {{a, b}, {a + 1, b}}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<pair<int, pair<pair<int, int>, pair<int, int>>>> MST;
        for (int j = 0; j < edges.size(); j++) {
            pair<int, pair<pair<int, int>, pair<int, int>>> cur_edge = edges[j];

            pair<int, int> v1 = cur_edge.second.first;
            pair<int, int> v2 = cur_edge.second.second;

            if (find_root(v1) == find_root(v2)) continue;

            union_set(v1, v2);
            MST.push_back(cur_edge);

            if (MST.size() == R * C - 1) break;
        }

        int cost = 0;
        for (int j = 0; j < MST.size(); j++) cost += MST[j].first;
        cout << cost << "\n";
    }

    return 0;
}