#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

long long candy(vector<long long> &v, long long X, long long K) {
    long long totalCandy = 0;
    for (long long score : v) {
        if (score > X) {
            totalCandy += score - X;
            if (totalCandy > K) {
                return totalCandy;
            }
        }
    }
    return totalCandy;
}

long long binary_search(vector <long long>&v, long long K) {
    long long left = 0;
    long long right = *max_element(v.begin(), v.end());
    long long result = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long candies = candy(v, mid, K);
        if (candies <= K) {
            result = mid;
            right = mid - 1;
        } else{
            left =  mid + 1;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    cin >> N >> K;
    
    vector <long long> scores(N);

    for (long long i = 0; i < N; i++) {
        cin >> scores[i];
    }

    cout << binary_search(scores, K);

    return 0;
}