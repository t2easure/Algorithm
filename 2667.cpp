#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void returnValue(vector <vector<int>> &map, queue<pair<int, int>> &q, vector <vector<int>> &visited, int N) {
    if (q.empty()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    return;
                }
            }
        }
    }
}

bool allVisited(vector<vector<int>> &map, vector<vector<int>> &visited, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            if (visited[i][j] == 0 && map[i][j] == 1) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> map(N, vector<int>(N));
    vector<vector<int>> visited(N, vector<int>(N, 0));
    queue <pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    vector <int> result;
    while (allVisited(map, visited, N) == false) {
        returnValue(map, q, visited, N);

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int homes = 1;
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N && visited[nx][ny] == 0 && map[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                    homes += 1;
                }
            }
        }

        result.push_back(homes);
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
    
    return 0;
}