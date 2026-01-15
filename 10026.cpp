#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> area(N);

    for (int i = 0; i < N; i++) {
        cin >> area[i];
    }

    int num = 0;
    queue <pair<int, int>> q;
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            if (!visited[a][b]) {
                char current = area[a][b];
                q.push({a, b});
                visited[a][b] = true;

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    visited[cur.first][cur.second] = true;
                    q.pop();

                    int dx[4] = {-1, 1, 0, 0};
                    int dy[4] = {0, 0, -1, 1};
                    for (int i = 0; i < 4; i++) {
                        int x = dx[i] + cur.first;
                        int y = dy[i] + cur.second;
                        if (x >= 0 && x < N && y >= 0 && y < N) {
                            if (visited[x][y] == false && area[x][y] == current) {
                                q.push({x, y});
                                visited[x][y] = true;
                            }
                        }
                    }
                }
                num += 1;
            }
        }
    }

    cout << num << " ";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (area[i][j] == 'R')
                area[i][j] = 'G';
        }
    }

    int num2 = 0;
    queue <pair<int, int>> q2;
    vector<vector<bool>> visited2(N + 1, vector<bool>(N + 1, false));
    
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            if (!visited2[a][b]) {
                char current = area[a][b];
                q2.push({a, b});
                visited2[a][b] = true;

                while (!q2.empty()) {
                    pair<int, int> cur = q2.front();
                    visited2[cur.first][cur.second] = true;
                    q2.pop();

                    int dx[4] = {-1, 1, 0, 0};
                    int dy[4] = {0, 0, -1, 1};
                    for (int i = 0; i < 4; i++) {
                        int x = dx[i] + cur.first;
                        int y = dy[i] + cur.second;
                        if (x >= 0 && x < N && y >= 0 && y < N) {
                            if (visited2[x][y] == false && area[x][y] == current) {
                                q2.push({x, y});
                                visited2[x][y] = true;
                            }
                        }
                    }
                }
                num2 += 1;
            }
        }
    }

    cout << num2 << " ";

    return 0;
}