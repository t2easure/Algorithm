#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> current(3), max_prev(3), min_prev(3);

    for (int i = 0; i < N; i++) {
        cin >> current[0] >> current[1] >> current[2];
        if (i == 0) {
            max_prev = current;
            min_prev = current;
        } else {
            vector <int> temp(3);
            temp[0] = max(max_prev[0], max_prev[1]) + current[0];
            temp[1] = *max_element(max_prev.begin(), max_prev.end()) + current[1];
            temp[2] = max(max_prev[1], max_prev[2]) + current[2];

            vector <int> temp2(3);
            temp2[0] = min(min_prev[0], min_prev[1]) + current[0];
            temp2[1] = *min_element(min_prev.begin(), min_prev.end()) + current[1];
            temp2[2] = min(min_prev[1], min_prev[2]) + current[2];

            max_prev = temp;
            min_prev = temp2;
        }

    }

    cout << *max_element(max_prev.begin(), max_prev.end()) << " " << *min_element(min_prev.begin(), min_prev.end()) << endl;

    return 0;
}