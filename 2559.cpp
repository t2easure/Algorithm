#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

long long binary_search(vector<long long>& v, long long S) {
    long long max_sum = INT_MIN;
    long long n = v.size();
    long long left = 0;
    long long right = S - 1;

    while (right < n) {
        int sum = accumulate(v.begin() + left, v.begin() + right + 1, 0);
        if (sum > max_sum) {
            max_sum = sum;
        } 
        left += 1;
        right = left + S - 1;
    }

    return max_sum;
}

int main() {
    long long N, S;
    cin >> N >> S;

    vector <long long> solutions(N);
    for (int i = 0; i < N; i++)
        cin >> solutions[i];

    long long result = binary_search(solutions, S);

    cout << result;

    return 0;
}