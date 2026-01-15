#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<long long> numbers(101);

    numbers[1] = 1;
    numbers[2] = 1;
    numbers[3] = 1;
    numbers[4] = 2;
    numbers[5] = 2;

    for (int i = 6; i <= 100; i++) {
        numbers[i] = numbers[i - 1] + numbers[i - 5];
    }

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << numbers[N] << "\n";
    }

    return 0;
}
