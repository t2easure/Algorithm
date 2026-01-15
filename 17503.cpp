#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits.h>

using namespace std;

bool preference(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first > b.first;
}

bool level(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main() {
    long long N, M, K;
    cin >> N >> M >> K;

    vector <pair<long long, long long>> beers(K);
    for (int i = 0; i < K; i++) {
        cin >> beers[i].first >> beers[i].second;
    }

    sort(beers.begin(), beers.end(), preference);
    long long initial_sum = 0;
    for (int i = 0; i < N; i++) {
        initial_sum += beers[i].first;
    }

    if (initial_sum < M) {
        cout << -1;
        return 0;
    }

    long long low = 1;
    long long high = (1LL << 31) - 1;
    long long ans = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;

        vector <pair<long long, long long>> valid_beers;
        for (int i = 0; i < K; i++) {
            if (mid >= beers[i].second) valid_beers.push_back(beers[i]);
        }

        if (valid_beers.size() >= N) {
            sort(valid_beers.begin(), valid_beers.end(), preference);

            long long sum = 0;
            for (int i = 0; i < N; i++) {
                sum += valid_beers[i].first;
            }

            if (sum >= M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else low = mid + 1;
    } 

    cout << ans << endl;

    return 0;
}