#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <pair<int ,vector <int>>> vertex;
    vector <int> visited(N + 1, 0);
    for (int i = 0; i <= N; i++) {
        vector <int> temp;
        vertex.push_back(make_pair(i, temp));
    }

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        vertex[a].second.push_back(b);
        vertex[b].second.push_back(a);
    }

    queue <int> q;
    vector <int> result; 

    if (vertex[1].first) {
        q.push(1);
        visited[1] = 1;
        result.push_back(1);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int j = 0; j < vertex[current].second.size(); j++) {
                int v = vertex[current].second[j];
                if (visited[v] == 0) {
                    q.push(v);
                    visited[v] = 1;
                    result.push_back(v);
                }
            }
        }
    }

    cout << result.size() - 1;

    return 0;
}