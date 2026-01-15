#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <long long> liquid(N);
    for (int i = 0; i < N; i++) cin >> liquid[i];

    int left = 0;
    int right = N - 1;
    long long max = abs(liquid[left] + liquid[right]);
    long long ans_left = liquid[left], ans_right = liquid[right];
    while (left < right) {
        long long made = liquid[left] + liquid[right];
        if (abs(made) < max) {
            max = abs(made);
            ans_left = liquid[left];
            ans_right = liquid[right];
        }

        if (made < 0) left += 1;
        else right -= 1;
    }
    if (ans_left < ans_right) cout << ans_left << " " << ans_right << endl;
    else cout << ans_right << " " << ans_left << endl;

    return 0;
}