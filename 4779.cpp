#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        string str = "";
        int limit = pow(3, N);
        for (int i = 0; i < limit; i++ )
            str += '-';
        while (limit != 1) {
            limit /= 3;
            for (int i = limit; i < pow(3, N); i += limit * 2) {
                for (int j = 0; j < limit; j += 1)
                    str[i + j] = ' ';
            }
        }
        cout << str << endl;
    }
}