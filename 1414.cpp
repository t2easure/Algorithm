#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> parent;

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
    int N;
    cin >> N;
    
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<pair<int, pair<int, int>>> edges;

    int all_cost = 0;
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            if (str[j] == '0') continue;
            if ('a' <= str[j] && str[j] <= 'z') {
                edges.push_back({str[j] - 'a' + 1, {i, j + 1}});
                all_cost += str[j] - 'a' + 1;
            }
            else if ('A' <= str[j] && str[j] <= 'Z') {
                edges.push_back({str[j] - 'A' + 27, {i, j + 1}});
                all_cost += str[j] - 'A' + 27;
            }
        }
    }

    sort(edges.begin(), edges.end());

    vector<pair<int, pair<int, int>>> MST;
    for (int i = 0; i < edges.size(); i++) {
        pair<int, pair<int, int>> cur_edge = edges[i];

        int v1 = cur_edge.second.first;
        int v2 = cur_edge.second.second;

        if (find_root(v1) == find_root(v2)) continue;

        union_set(v1, v2);
        MST.push_back(cur_edge);
        if (MST.size() == N - 1) break;
    }

    if (MST.size() < N - 1) {
        cout << -1 << endl;
        return 0;
    }

    int cost = 0;
    for (int i = 0; i < MST.size(); i++) cost += MST[i].first;

    cout << all_cost - cost << "\n";
    return 0;
}