#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int map[500][500];
int dp[500][500];
int nx[] = {0, 0, 1, -1};
int ny[] = {1, -1, 0, 0};

int dfs (int x, int y) {
    if (x == N - 1 && y == M - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int dx = x + nx[i];
        int dy = y + ny[i];

        if (dx >= 0 && dy >= 0 && dx < N && dy < M) {
            // 도착할 수 있으면 거기서부터 도착지까지 가는 길의 수를 내 길의 수에 더한다.
            if (map[dx][dy] < map[x][y]) dp[x][y] += dfs(dx, dy);
        }
    }

    return dp[x][y];
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);

    return 0;
}