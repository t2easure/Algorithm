#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector <pair<int,vector <int>>> vertex;
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
    int number = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            q.push(i);
            visited[i] = 1;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int j = 0; j < vertex[current].second.size(); j++) {
                    int v = vertex[current].second[j];
                    if (visited[v] == 0) {
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
            number += 1;
        }
    }

    cout << number;

    return 0;
} 