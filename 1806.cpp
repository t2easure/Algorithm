#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long binary_search(vector<long long>& v, long long S) {
    long long sum = 0;
    long long n = v.size();
    long long left = 0;
    long long right = -1;
    long long min_length = n + 1;

    while (right < n) {
        if (sum >= S) {
            min_length = min(min_length, right - left + 1);
            sum -= v[left++];
        } else {
            right += 1;
            if (right >= n) break;
            sum += v[right];
        }
    }

    return min_length == n + 1 ? 0 : min_length;
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