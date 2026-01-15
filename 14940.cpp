#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void returnValue(vector <vector<int>> &result, vector <vector<int>> &map, queue<pair<int, int>> &q, vector <vector<int>> &visited, int N, int M) {
    if (q.empty()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 2 && visited[i][j] == 0) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    result[i][j] = 0;
                    return;
                }
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    vector<vector<int>> result(N, vector<int>(M, -1));
    queue <pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) result[i][j] = 0;
        }
    }

    returnValue(result, map, q, visited, N, M);

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && visited[nx][ny] == 0 && map[nx][ny] == 1) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                result[nx][ny] = result[x][y] + 1;
            }
        }

    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}