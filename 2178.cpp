#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M, N;
    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(M));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue <pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++) {
            arr[i][j] = input[j] - '0';
        }
    }

    if (arr[0][0] == 1) {
        q.push(make_pair(0, 0));
        visited[0][0] = 1;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == N - 1 &&  y == M - 1){
            cout << visited[x][y] << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = visited[x][y] + 1;
                return 0;
            }
        }
    }

    cout << "-1";

    return 0;
} 