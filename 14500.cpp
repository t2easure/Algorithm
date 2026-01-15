#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int blue (vector <vector<int>> &v) {
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j + 3 < M) {
                int sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3];
                if (sum > max) max = sum;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + 3 < N) {
                int sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j];
                if (sum > max) max = sum;
            }
        }
    }
    return max;
}

int yellow(vector <vector<int>> &v) {
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + 1 < N && j + 1 < M) {
                int sum = v[i][j] + v[i][j + 1];
                sum += v[i + 1][j] + v[i + 1][j + 1];
                if (sum > max) max = sum;
            }
        }
    }
    return max;
}

int orange(vector <vector<int>> &v) {
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int sum = 0;
            if (i + 1 < N && i + 2 < N && j + 1 < M)
                sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j + 1];
            if (sum > max) max = sum;
            if (i + 1 < N && i + 2 < N && j - 1 >= 0)
                sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j - 1];
            if (sum > max) max = sum;
            if (j + 1 < M && j + 2 < M && i + 1 < N)
                sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j];
            if (sum > max) max = sum;
            if (j + 1 < M && j + 2 < M && i + 1 < N)
                sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2];
            if (sum > max) max = sum;
        }
    }
    return max;
} 

int green(vector <vector<int>> &v) {
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int sum = 0;
            if (i + 1 < N && j + 1 < M && i + 2 < N) 
                sum = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1];
            if (sum > max) max = sum;
            if (i + 1 < N && j - 1 >= 0 && i + 2 < N)
                sum = v[i][j] + v[i + 1][j] + v[i + 1][j - 1] + v[i + 2][j - 1];
            if (sum > max) max = sum;
            if (i + 1 < N && j + 1 < M && j - 1 >= 0)
                sum = v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 1][j - 1];
            if (sum > max) max = sum;
            if (i + 1 < N && j - 1 >= 0 && j + 1 < M)
                sum = v[i][j] + v[i][j - 1] + v[i + 1][j] + v[i + 1][j + 1];
            if (sum > max) max = sum;
        }
    }
    return max;
}

int pink(vector<vector<int>>& v) {
    int max = 0;
    // Check all rotations of 'T' shape
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Standard T-shape (┬)
            if (i + 1 < N && j + 1 < M && j - 1 >= 0) {
                int sum = v[i][j] + v[i + 1][j - 1] + v[i + 1][j] + v[i + 1][j + 1];
                max = std::max(max, sum);
            }
            // Upside down T-shape (┴)
            if (i - 1 >= 0 && j + 1 < M && j - 1 >= 0 && i + 1 < N) {
                int sum = v[i][j] + v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
                max = std::max(max, sum);
            }
            // Left T-shape (├)
            if (j + 1 < M && i + 1 < N && i + 2 < N) {
                int sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1];
                max = std::max(max, sum);
            }
            // Right T-shape (┤)
            if (j - 1 >= 0 && i + 1 < N && i + 2 < N) {
                int sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j - 1];
                max = std::max(max, sum);
            }
        }
    }
    return max;
}

int main() {
    cin >> N >> M;
    vector <vector<int>> v(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> v[i][j];
    }

    vector<int> result = {blue(v), yellow(v), orange(v), green(v), pink(v)};

    cout << *max_element(result.begin(), result.end());

    return 0;
}