#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool isValid(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited, int shark_size) {
    return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y] && grid[x][y] <= shark_size;
}

bool compare(const tuple <int, int, int> &a, const tuple <int, int, int> &b) {
    if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
    if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
    return get<1>(a) < get<1>(b);
}

int main() {
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N, 0));
    tuple <int, int, int> start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 9) {
                start = make_tuple(i, j, 0);
                grid[i][j] = 0;
            }
        }
    }

    int shark_size = 2;
    int eaten = 0;
    int time = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[get<0>(start)][get<1>(start)] = false;
    queue<tuple<int, int, int>> q;
    q.push(start);

    while (!q.empty()) {
        vector<tuple<int, int, int>> fish;
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            int x, y, dist;
            tie(x, y, dist) = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (!isValid(nx, ny, grid, visited, shark_size)) continue;

                visited[nx][ny] = true;
                if (grid[nx][ny] > 0 && grid[nx][ny] < shark_size) fish.push_back(make_tuple(nx, ny, dist+ 1));
                q.push(make_tuple(nx, ny, dist + 1));
            }
        }

        if (!fish.empty()) {
            sort(fish.begin(), fish.end(), compare);
            int fx, fy, fd;
            tie(fx, fy, fd) = fish[0];
            time += fd;
            eaten += 1;
            if (eaten == shark_size) {
                eaten = 0;
                shark_size += 1;
            }
            grid[fx][fy] = 0;
            while (!q.empty()) q.pop();
            q.push(make_tuple(fx, fy, 0));
            visited = vector<vector<bool>>(N, vector<bool>(N, false));
            visited[fx][fy] = true;
        }
    }

    cout << time << endl;
    return 0;
}