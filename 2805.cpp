#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool partition(const vector <long long>& num, long long mid, long long M) {
    long long currentSum = 0;

    for (int i = 0; i < num.size(); i++) {
        long long current = num[i];
        if (current < mid) continue;
        else currentSum += current - mid;
    }

    if (M <= currentSum) return true;
    return false;
}

int binary_search(const vector <long long>& num, long long M) {
    long long left = 0;
    long long right = *max_element(num.begin(), num.end());
    long long result = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (partition(num, mid, M)) {
            result = mid;
            left = mid + 1;
        } else right = mid - 1;
    }

    return result;
}

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> trees(N);
    for (int i = 0; i < N; i++)
        cin >> trees[i];
    
    cout << binary_search(trees, M);
    return 0;
}