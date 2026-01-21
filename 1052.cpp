#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_transition(int N) {

    int N_num = 0;
    while (N >= 1) {
        if (N % 2 == 1) N_num += 1;
        N /= 2;
    }
    return N_num;
}

int main() {
    int N, K;
    cin >> N >> K;

    int N_num = binary_transition(N);

    int result = 0;
    while (K < N_num) {
        result += 1;
        N += 1;
        N_num = binary_transition(N);
    }

    cout << result;
    return 0;
}