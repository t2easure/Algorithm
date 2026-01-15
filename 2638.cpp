#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 2는 공기 유입됨
// 0은 공기 유입되지 않음

void contact_cheese(queue<pair<int, int>> &q, vector<vector<int>> &visited, vector<vector<int>> &cheese) {
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && cheese[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    cheese[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void disappear_cheese(vector<vector<int>> &visited, vector<vector<int>> &cheese) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cheese[i][j] == 1) {
                int num = 0;
                for (int a = 0; a < 4; a++) {
                    int nx = i + dx[a];
                    int ny = j + dy[a];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if (cheese[nx][ny] == 2) num += 1;
                    }
                }

                if (num >= 2) cheese[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cheese[i][j] == 2) cheese[i][j] = 0;
        }
    }
}

bool check_all_disappear(vector<vector<int>> &cheese) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cheese[i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    pair<int, int> start = {-1, -1};
    vector<vector<int>> cheese(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cheese[i][j];
            if (start.first == -1 && cheese[i][j] == 0) start = {i, j};
        }
    }

    int time = 0;
    while (!check_all_disappear(cheese)) {
        time += 1;
        vector<vector<int>> visited(N, vector<int>(M, 0));
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = 1;
        contact_cheese(q, visited, cheese);
        disappear_cheese(visited, cheese);
    }
    
    cout << time;
    return 0;
}