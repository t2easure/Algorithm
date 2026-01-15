#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> longestLengths(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] < A[j]) {
                longestLengths[i] = max(longestLengths[i], longestLengths[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        maxLength = max(maxLength, longestLengths[i]);
    }

    cout << maxLength;

    return 0;
}
