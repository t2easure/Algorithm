#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int day;
    int pay;
} Consulting;

int main() {
    int N;
    cin >> N;

    vector<Consulting> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].day >> v[i].pay;
    }

    vector <int> dp(N + 1, 0);

    for(int i = N - 1; i >= 0; i--){
        int nextday = i + v[i].day;

        if(nextday <= N){
            dp[i] = max(v[i].pay + dp[nextday], dp[i + 1]);
        }
        else{
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0] << endl;

    return 0;
}

