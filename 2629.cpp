#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dp[31][40001]; // (추의 개수, 무게)

int main() {
    int N;
    cin >> N;
    vector <int> weights(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> weights[i];
    }

    dp[0][0] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 40000; j++) {
            if (dp[i - 1][j]) {
                dp[i][j] = true;
                if (weights[i] + j <= 40000) dp[i][weights[i] + j] = true;
                dp[i][abs(weights[i] - j)] = true;
            }
        }
    }

    int M;
    cin >> M;
    for (int i = 1; i <= M; i++) {
        int num;
        cin >> num;

        bool is_Exist = false;
        for (int k = 1; k <= N; k++) {
            if (dp[k][num]) {
                is_Exist = true;
                break;
            }
        }

        if (is_Exist) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}