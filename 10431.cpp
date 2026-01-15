#include <iostream>
#include <vector>

using namespace std;

int main() {
    int P;
    cin >> P;

    for (int i = 0; i < P; i++) {
        int T;
        cin >> T;
        vector <int> height(20, 0);
        for (int j = 0; j < 20; j++)
            cin >> height[j];

        vector <int> result(40, 0);
        result[0] = height[0];
        int number = 0;
        int last = 19;
        for (int j = 1; j < 20; j++) {
            result[last] = height[j];
            for (int a = 0; a < last; a++) {
                if (result[last] < result[a]) {
                    int over = 0;
                    for (int b = last; b > a; b --) {
                        result[b] = result[b - 1];
                        if (result[b] != 0) {
                            over += 1;
                        }
                    } result[a] = height[j];
                    number += over;
                    break;
                }
            }
            last += 1;
        }
        cout << T << " " << number << endl;
    }
}