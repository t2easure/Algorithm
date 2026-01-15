#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> adj; 
vector<int> parent;
vector<bool> visited; 

void dfs(int node) {
    stack<int> s;
    s.push(node);
    visited[node] = true;

    while (!s.empty()) {
        int next = s.top();
        s.pop();

        for (int i = 0; i < adj[next].size(); i++) {
            int v = adj[next][i];
            if (visited[v] == false) {
                visited[v] = true;
                parent[v] = next;
                s.push(v);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N + 1);
    parent.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}