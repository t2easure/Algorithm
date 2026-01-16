#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> dp(N + 1, 0);
    // N이 홀수면 3xN을 2x1 타일로 채울 수 없으므로 0이 출력됨 (초기값 0 유지)
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 3 * 3 + 2 * 1; // 4일 때 3x2 두번 9개, 3x4 특이모양 두개

    for (int i = 5; i <= N; i ++) {
        if (i % 2 != 0) continue;
        dp[i] = dp[i - 2] * 3; // i-2 단계에서 3x2 모양 3가지를 붙이는 경우
        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2; // 특이한 모양 2가지씩 (i - 4, i - 6, ...)
        }
    }

    cout << dp[N] << endl;

    return 0;
}