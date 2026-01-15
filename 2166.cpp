#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct {
    double x;
    double y;
} Point;

int main() {
    int N;
    cin >> N;

    vector <Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double sum = 0;
    double sum2 = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += points[i].x * points[i + 1].y;
        sum2 += points[i].y * points[i + 1].x;
    }
    sum += points[N - 1].x * points[0].y;
    sum2 += points[N - 1].y * points[0].x;

    double result = abs(sum - sum2) / 2;

    cout << fixed << setprecision(1) << result << endl;

    return 0;
}