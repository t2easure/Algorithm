#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> stairs(N + 1);
    vector <int> dp(N + 1);

    for (int i = 1; i <= N; i++) 
        cin >> stairs[i];
    
    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];

    for (int i = 3; i <= N; i++)
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);

    cout << dp[N];

    return 0;
}