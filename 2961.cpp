#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> ingredients(N);
    for (int i = 0; i < N; i++) {
        cin >> ingredients[i].first >> ingredients[i].second;
    }

    long long min_diff = 2e9;

    for (int i = 1; i <= (1 << N) -1; i++) {
        long long sour = 1;
        long long bitter = 0;

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sour *= ingredients[j].first;
                bitter += ingredients[j].second;
            }
        }

        long long diff = abs(sour - bitter);
        if (diff < min_diff) min_diff = diff;
    }

    cout << min_diff << endl;

    return 0;
}