#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    int P[1000];
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }

    sort(P, P+N);

    int sum = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j <= i; j++){
            sum += P[j];
        }
    }

    cout << sum;
}