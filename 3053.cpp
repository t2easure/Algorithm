#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    double R;
    cin >> R;

    cout << fixed;
    cout.precision(6);
    cout << R * R * 3.14159265358979 << endl;
    cout << (double)(2 * R * R) << endl;

    return 0;
}