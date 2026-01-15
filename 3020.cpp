#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, H;
    cin >> N >> H;

    vector <int> obstacles(H + 1, 0);
    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        if (i % 2 == 0) {
            obstacles[1]++;
            if (num + 1 <= H) obstacles[num + 1]--;
        } else obstacles[H - num + 1]++;
    }

    int current = 0;
    int count = 0;
    int min = N;

    for (int i = 1; i <= H; i++) {
        current += obstacles[i];
        if (current < min) {
            min = current;
            count = 1;
        } else if (current == min) count += 1;
    }

    cout << min << " " << count;

    return 0;
}