#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <vector<int>> dp(N + 1, vector<int>());
    vector <int> number(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        cin >> number[i];
    }

    if (N == 1) {
        cout << "1\n" << number[1];
        return 0;
    }

    dp[1] = {number[1]};

    if (number[1] < number[2]) {
        dp[2] = {number[1], number[2]};
    } else {
        dp[2] = {number[2]};
    }

    for (int i = 3; i <= N; i++) {
        int max_index = -1;
        int max_length = 0;

        for (int j = 1; j <= i - 1; j++) {
            if (number[j] < number[i]) {
                if (max_length < dp[j].size()) {
                    max_length = dp[j].size();
                    max_index = j;
                }
            }
        }

        if (max_index != -1) dp[i] = dp[max_index];
        dp[i].push_back(number[i]);
    }

    int index = 1;
    for (int i = 1; i <= N; i++) {
        if (dp[i].size() > dp[index].size()) index = i;
    }

    cout << dp[index].size() << endl;
    for (int i = 0; i < dp[index].size(); i++) {
        cout << dp[index][i] << " ";
    }

    return 0;
}