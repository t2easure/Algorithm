#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <long long> parent;

long long find_root(long long x) {
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void union_set(long long x, long long y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) parent[y] = x;
}

bool compare(pair<pair<long long, long long>, pair<long long, long long>> a, pair<pair<long long, long long>, pair<long long, long long>> b) {
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

int main() {
    long long n, Q;
    cin >> n >> Q;

    parent.resize(n + 1);
    for (long long i = 1; i <= n; i++) parent[i] = i;

    vector<pair<pair<long long, long long>, pair<long long, long long>>> edges;
    for (int i = 1; i <= Q; i++) {
        long long from, to, cost, time;
        cin >> from >> to >> cost >> time;
        edges.push_back({{cost, time}, {from, to}});
    }

    sort(edges.begin(), edges.end(), compare);

    vector<pair<pair<long long, long long>, pair<long long, long long>>> MST;
    long long last_time = 0;

    for (int i = 0; i < Q; i++) {
        pair<pair<long long, long long>, pair<long long, long long>> cur_edge = edges[i];

        long long v1 = cur_edge.second.first;
        long long v2 = cur_edge.second.second;

        if (find_root(v1) == find_root(v2)) continue;

        union_set(v1, v2);
        MST.push_back(cur_edge);

        last_time = max(last_time, cur_edge.first.second);

        if (MST.size() == n - 1) break;
    }

    if (MST.size() < n - 1) {
        cout << -1 << "\n";
        return 0;
    }

    long long cost = 0;
    for (int i = 0; i < MST.size(); i++) cost += MST[i].first.first;

    cout << last_time << " " << cost << "\n";

    return 0;
}