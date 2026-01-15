#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string S;
        cin >> S;

        int len = S.length();
        int n = 1;
        while(n * n < len){
            n ++;
        }


        char arr[100][100];
        int idx = 0;
        for(int b = 0; b < n; b++){
            for(int a = n - 1; a >= 0; a--){
                if(idx < len){
                    arr[a][b] = S[idx];
                    idx ++;
                }
            }
        }

        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                if(arr[a][b] != 0){
                    cout << arr[a][b];
                }
            }
        }

        cout << "\n";
    }
}