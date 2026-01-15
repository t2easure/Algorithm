#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<vector<int>> matrix_multiplication(vector <vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    vector<vector<int>> result = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] = (result[i][j] + (long long)(matrix1[i][k]) * (long long)(matrix2[k][j])% MOD) % MOD;
            }
        }
    }
    return result;    
}

vector<vector<int>> matrixExp(long long n) {
    vector<vector<int>> result = {{1, 0}, {0, 1}};
    vector<vector<int>> base = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) result = matrix_multiplication(result, base);
        base = matrix_multiplication(base, base);
        n /= 2;
    }

    return result;
}

int main() {
    long long n;
    cin >> n;
    vector<vector<int>> result = matrixExp(n);
    cout << result[0][1] << endl;

    return 0;
}