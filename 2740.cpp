#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M;

    int A[100][100] = {0};
    int B[100][100] = {0};
    int S[100][100] = {0};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cin >> A[i][j];
        }
    }

    cin >> M >> K;

    for(int j = 0; j < M; j++){
        for(int t = 0; t < K; t++){
            cin >> B[j][t];
        }
    }

    for(int i = 0; i < N; i ++){
        for(int t = 0; t < K; t++){
            for(int j = 0; j < M; j++){
                S[i][t] += A[i][j] * B[j][t];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int t = 0; t < K; t++){
            cout << S[i][t] << " ";
        }
        cout << "\n";
    }

    return 0;
}