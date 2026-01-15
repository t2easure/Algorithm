#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool partition(const vector <int>& num, int MaxSum, int M) {
    int currentSum = 0;;
    int partition = 1;

    for (int i = 0; i < num.size(); i++) {
        int current = num[i];
        if (MaxSum < currentSum + current) {
            currentSum = current;
            partition += 1;

            if (partition > M) return false;
            if (current > MaxSum) return false;

        } else {
            currentSum += current;
        }
    }

    return true;
}

int binary_search(const vector <int>& num, int M) {
    int left = *max_element(num.begin(), num.end());
    int right = accumulate(num.begin(), num.end(), 0);
    int result = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (partition(num, mid, M)) {
            result = mid;
            right = mid - 1;
        } else left = mid + 1;
    }

    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> lectures(N);
    for (int i = 0; i < N; i++)
        cin >> lectures[i];
    
    cout << binary_search(lectures, M);
    return 0;
}