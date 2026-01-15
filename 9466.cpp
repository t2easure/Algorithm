#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T -- ){
        int n; cin >> n;
        vector <int> students(n + 1);
        for (int i = 1; i <= n; i ++) cin >> students[i];

        vector<bool> visited(n + 1, false);
        vector<bool> finished(n + 1, false);
        int teamCount = 0;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            stack <int> s;
            vector<int> path;
            s.push(i);

            while (!s.empty()) {
                int current = s.top();

                if (!visited[current]) {
                    visited[current] = true;
                    s.push(students[current]);
                    path.push_back(current);
                } else {
                    s.pop();

                    if (!finished[current]) {
                        auto it = find(path.begin(), path.end(), current);
                        if (it != path.end()) {
                            int idx = it - path.begin();
                            teamCount += path.size() - idx;
                        }
                    }

                    break;
                }
            }

            for (int node : path) finished[node] = true;
        }

        cout << n - teamCount << "\n";
    }

    return 0;
}