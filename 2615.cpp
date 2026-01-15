#include <iostream>
#include <vector>

using namespace std;

bool isOutOfBounds(int x, int y) {
    return x < 0 || x >= 19 || y < 0 || y >= 19;
}

bool isSame(vector<vector<int>>& v, int i, int j, int x, int y) {
    if (isOutOfBounds(i + x, j + y)) return false;
    return v[i][j] == v[i + x][j + y];
}

int main() {
    vector<vector<int>> v(19, vector<int>(19, 0));

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) cin >> v[i][j];
    }

    const int dx[] = {1, 0, 1, -1};
    const int dy[] = {0, 1, 1, 1};

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (v[i][j] != 0) {
                for (int a = 0; a < 4; a++) {
                    if (isOutOfBounds(i - dx[a], j - dy[a]) || v[i - dx[a]][j - dy[a]] != v[i][j]) {
                        int current_x = i;
                        int current_y = j;
                        int count = 1;

                        while (count < 5 && isSame(v, current_x, current_y, dx[a], dy[a])) {
                            current_x += dx[a];
                            current_y += dy[a];
                            count++;
                        }

                        if (count == 5 && (isOutOfBounds(current_x + dx[a], current_y + dy[a]) || v[current_x + dx[a]][current_y + dy[a]] != v[i][j])) {
                            cout << v[i][j] << endl;
                            cout << i + 1 << " " << j + 1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "0" << endl;
    return 0;
}
