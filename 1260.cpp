#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector <pair<int,vector <int>>> vertex(N + 1);
    vector <int> visited(N + 1, 0);
    for (int i = 0; i <= N; i++) {
        vertex[i].first = i;
    }

    int edges;
    cin >> edges;

    int start;
    cin >> start;

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        vertex[a].second.push_back(b);
        vertex[b].second.push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(vertex[i].second.begin(), vertex[i].second.end());
    }

    stack <int> s;

    s.push(start);
    visited[start] = 1;
    cout << start << " ";

    while (!s.empty()) {
        int current = s.top();
        bool hasUnvisited = false;

        for (int j = 0; j < vertex[current].second.size(); j++) {
            int adj = vertex[current].second[j];
            if (!visited[adj]) {
                s.push(adj);
                visited[adj] = 1;
                cout << adj << " ";
                hasUnvisited = true;
                break;
            }
        }

        if (!hasUnvisited) {
            s.pop();
        }
    }

    cout << "\n";

    for (int i = 0; i <= N; i++)
        visited[i] = 0;

    queue <int> q;

    q.push(start);
    visited[start] = 1;
    cout << start << " ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int j = 0; j < vertex[current].second.size(); j++) {
            int v = vertex[current].second[j];
            if (visited[v] == 0) {
                q.push(v);
                visited[v] = 1;
                cout << v << " ";
            }
        }
    }

    return 0;
} 