#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<long long, long long> binary_search(vector <long long>& v) {
    long long left = 0;
    long long right = v.size() - 1;
    long long result = v[left] + v[right];
    pair <long long, long long> best_pair = make_pair(left, right);

    while (left < right) {
        long long sum = v[left] + v[right];
        if (abs(sum) < abs(result)) {
            result = sum;
            best_pair = make_pair(left, right);
        }

        if (sum < 0) left += 1;
        else right -= 1;
    }

    return best_pair;
}

int main() {
    int N;
    cin >> N;

    vector <long long> solutions(N);
    for (int i = 0; i < N; i++)
        cin >> solutions[i];

    sort(solutions.begin(), solutions.end());

    pair<long long, long long> result = binary_search(solutions);

    cout << solutions[result.first] << " " << solutions[result.second];

    return 0;
}