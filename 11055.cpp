#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> A(N + 1);
    vector <int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[i] = A[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}