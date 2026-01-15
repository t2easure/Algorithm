#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2, 0)));
    queue <pair<pair<int, int>, int>> q;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++) {
            arr[i][j] = input[j] - '0';
        }
    }

    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int broken = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front().first;
        int broke = q.front().second;
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == N - 1 && y == M - 1) {
            cout << visited[x][y][broke] << "\n";
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (arr[nx][ny] == 0 && visited[nx][ny][broke] == 0) {
                    visited[nx][ny][broke] = visited[x][y][broke] + 1;
                    q.push({{nx, ny}, broke});
                }
                if (broke == 0 && arr[nx][ny] == 1 && visited[nx][ny][1] == 0) {
                    visited[nx][ny][1] = visited[x][y][0] + 1;
                    q.push({{nx, ny}, 1});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}