#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int R, C;
vector<vector<bool>> visited;
vector<bool> used(26, false);
vector<string> board;
int max_length = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int length) {
    max_length = max(max_length, length);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if (!visited[nx][ny] && !used[board[nx][ny] - 'A']) {
                visited[nx][ny] = true;
                used[board[nx][ny] - 'A'] = true;
                dfs(nx, ny, length + 1);
                visited[nx][ny] = false;
                used[board[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main() {
    cin >> R >> C;
    board.resize(R);
    visited.assign(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) cin >> board[i];

    visited[0][0] = true;
    used[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << max_length << endl;

    return 0;
}