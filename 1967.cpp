#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <pair<int,vector <pair<int, int>>>> vertex(n + 1);
    vector <int> visited(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].second.push_back({b, c});
        vertex[b].second.push_back({a, c});
    }
    
    stack <pair<int, int>> s;
    int farthestNode = 1; 
    int maxDistance = 0;

    s.push({1, 0});
    visited[1] = 1;

    while (!s.empty()) {
        pair<int, int> current = s.top();
        s.pop();

        if (current.second > maxDistance) {
            maxDistance = current.second;
            farthestNode = current.first;
        }

        for (int i = 0; i < vertex[current.first].second.size(); i++) {
            pair<int, int> adj = vertex[current.first].second[i];
            if (!visited[adj.first]) {
                visited[adj.first] = 1;
                s.push({adj.first, current.second + adj.second});
            }
        }
    }

    fill(visited.begin(), visited.end(), 0);

    maxDistance = 0; 
    s.push({farthestNode, 0});
    visited[farthestNode] = 1;

    while (!s.empty()) {
        pair<int, int> current = s.top();
        s.pop();

        if (current.second > maxDistance) {
            maxDistance = current.second;
        }

        for (int i = 0; i < vertex[current.first].second.size(); i++) {
            pair<int, int> adj = vertex[current.first].second[i];
            if (!visited[adj.first]) {
                visited[adj.first] = 1;
                s.push({adj.first, current.second + adj.second});
            }
        }
    }

    cout << maxDistance << endl;

    return 0;
}