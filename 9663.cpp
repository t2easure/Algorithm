#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int result = 0;

bool isValid(const vector<int> &rows, int current_row, int col) {
    for (int i = 0; i < current_row; i++) {
        if (rows[i] == col || abs(rows[i] - col) == current_row - i) return false;
    }
    return true;
}

void placeQueens(int row, vector<int> rows) {
    if (row == N) {
        result += 1;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isValid(rows, row, i)) {
            rows[row] = i;
            placeQueens(row + 1, rows);
        }
    }
}

int main() {
    cin >> N;
    vector<int> rows(N);
    placeQueens(0, rows);
    cout << result;
    return 0;
}