#include <iostream>

using namespace std;

int main() {
    long long S;
    cin >> S;

    long long N = 1;
    long long sum = 0;

    while (sum + N <= S) {
        sum += N;
        N++;
    }

    cout << N - 1 << "\n";

    return 0;
}
