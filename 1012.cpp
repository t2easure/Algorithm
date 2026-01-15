#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for (int a = 0; a < T; a++) {
        int M, N, K;
        cin >> M >> N >> K;

        int arr[50][50] = {0};
        int visited[50][50] = {0};
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> b >> a;

            arr[a][b] = 1;
        }

        int insects = 0;
        queue <pair<int, int>> q;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0 && arr[i][j] == 1) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();

                        int x = current.first;
                        int y = current.second;
                        if (arr[x + 1][y] == 1 && visited[x + 1][y] == 0 && x + 1 < N) {
                            q.push(make_pair(x + 1, y));
                            visited[x+1][y] = 1;
                        }
                        if (arr[x][y + 1] == 1 && visited[x][y + 1] == 0 && y + 1 < M) {
                            q.push(make_pair(x, y+1));
                            visited[x][y+1] = 1;
                        }
                        if (arr[x - 1][y] == 1 && visited[x-1][y] == 0 && x - 1 >= 0) {
                            q.push(make_pair(x-1, y));
                            visited[x-1][y] = 1;
                        }
                        if (arr[x][y- 1] == 1 && visited[x][y - 1] == 0 && y - 1 >= 0) {
                            q.push(make_pair(x, y-1));
                            visited[x][y-1] = 1;
                        }
                    }
                    insects += 1;
                }
            }
        }
        cout << insects << endl;
    }

    return 0;
} 