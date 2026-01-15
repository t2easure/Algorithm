#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> lab;

void spreadVirus(vector<vector<int>> &map, vector<vector<int>> &visited) {
    queue <pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && map[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                map[nx][ny] = 2;
            }
        }
    }
}

int calculateSafeArea(vector<vector<int>> &map) {
    int safeArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) safeArea += 1;
        }
    }
    return safeArea;
}

int maxSafeArea() {
    int result = 0;
    vector<pair<int, int>> emptySpaces;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == 0) emptySpaces.push_back({i, j});
        }
    }

    vector<int> comb(emptySpaces.size(), 1);
    fill(comb.begin(), comb.begin() + emptySpaces.size() - 3, 0);

    do {
        vector<vector<int>> map = lab;
        vector<vector<int>> visited(N, vector<int>(M, 0));

        for (int i = 0; i < emptySpaces.size(); i++) {
            if (comb[i]) map[emptySpaces[i].first][emptySpaces[i].second] = 1;
        }

        spreadVirus(map, visited);
        result = max(result, calculateSafeArea(map));
    } while (next_permutation(comb.begin(), comb.end()));

    return result;
}

int main() {
    cin >> N >> M;
    lab.assign(N, vector<int> (M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> lab[i][j];
    }

    cout << maxSafeArea() << endl;

    return 0;
}