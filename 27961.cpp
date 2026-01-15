#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    long long number = 1;
    long long current = 1;

    while (current < N) {
        if (N >= 2 * current) {
            number += 1;
            current *= 2;
        } else {
            number += 1;
            current = N;
        }
    }

    cout << number;

    return 0;
}