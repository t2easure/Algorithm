#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        int distance = y - x;

        int max_move = static_cast<int>(sqrt(distance));
        if (max_move * max_move == distance) {
            cout << 2 * max_move - 1 << endl;
        } else if (distance <= max_move * max_move + max_move) {
            cout << 2 * max_move << endl; // (N + 1) * N -> 등차수열의 합 성질
        } else {
            cout << 2 * max_move + 1 << endl;
        }
    }

    return 0;
}
