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
    vector <int> number(N);
    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    int M;
    cin >> M;

    vector <int> sum(N , 0);
    sum[0] = number[0];
    for(int i = 1; i < N; i++){
        sum[i] = sum[i - 1] + number[i];
    }

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            cout << sum[b - 1] << "\n";
        } else {
            cout << sum[b - 1] - sum[a - 2] << "\n";
        }
    }
}