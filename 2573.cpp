#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool allMelted(vector<vector<int>> &mountains, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mountains[i][j] > 0) return false;
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector <vector<int>> mountains(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mountains[i][j];
        }
    }

    vector <vector<int>> visited(N, vector<int>(M, 0));
    queue <pair<int, int>> q;

    int time = 0;
    int number = 0;

    int nx[4] = {-1, 1, 0, 0};
    int ny[4] = {0, 0, 1, -1};
    while (number < 2) {
        number = 0;
        vector<vector<int>> current = mountains;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mountains[i][j] > 0) {
                    for (int a = 0; a < 4; a++) {
                        int x = i + nx[a];
                        int y = j + ny[a];

                        if (x >= 0 && x < N && y >= 0 && y < M && current[x][y] == 0) {
                            if (mountains[i][j] > 0) mountains[i][j] -= 1;
                        }
                    }
                }
            }
        }

        time += 1;

        if (allMelted(mountains, N, M)) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0 && mountains[i][j] != 0) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();

                        for (int a = 0; a < 4; a++) {
                            int x = current.first + nx[a];
                            int y = current.second + ny[a];

                            if (x >= 0 && x < N && y >= 0 && y < M && mountains[x][y] > 0 && visited[x][y] == 0) {
                                visited[x][y] = 1;
                                q.push(make_pair(x, y));
                            }
                        }
                    }
                    number += 1;
                }
            }
        }
    }

    if (number >= 2) cout << time << "\n";
    else cout << "0\n";

    return 0;
}