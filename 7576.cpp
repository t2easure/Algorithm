#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;  

    vector<vector<int>> boxes(N + 1, vector<int> (M + 1));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> boxes[i][j];
            if (boxes[i][j] == 1) q.push({i, j});
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int days = -1;
    while (!q.empty()) {
        days += 1;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair <int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (boxes[nx][ny] == 0) {
                        boxes[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (boxes[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << days;

    return 0;
}