#include <iostream>
#include <string>

using namespace std;

int findMin(char board[][50], int m, int n){
    char standard1 = board[m][n];
    char standard2;
    if(standard1 == 'B'){
        standard2 = 'W';
    }
    else{
        standard2 = 'B';
    }

    int num1 = 0;

    for(int i = m; i < 8 + m; i++){
        for(int j = n; j < 8 + n; j ++){
            if((i + j) % 2 == 0){
                if(board[i][j] != standard1){
                    num1 ++;
                }
            }
            else{
                if(board[i][j] != standard2){
                    num1 ++;
                }
            }
        }
    }

    int num2 = 0;
    for(int i = m; i < 8 + m; i++){
        for(int j = n; j < 8 + n; j++){
            if((i + j) % 2 == 0){
                if(board[i][j] != standard2){
                    num2++;
                }
            }
            else{
                if(board[i][j] != standard1){
                    num2++;
                }
            }
        }
    }

    return min(num1, num2);
}

int main(){
    int M, N;
    cin >> N >> M;

    char board[50][50];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    int min = findMin(board, 0, 0);

    for(int i = 0; i <= N - 8; i ++){
        for(int j = 0; j <= M - 8; j++){
            if(min > findMin(board, i, j)){
                min = findMin(board, i, j);
            }
        }
    }
    
    cout << min;

    return 0;
}