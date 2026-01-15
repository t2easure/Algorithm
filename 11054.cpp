#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <int> v(N + 1);
    vector <int> inc(N + 1, 1);
    vector <int> dec(N + 1, 1);

    for (int i = 1; i <= N; i++) cin >> v[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (v[i] > v[j]) {
                inc[i] = max(inc[i], inc[j] + 1);
            } 
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int j = N; j > i; j--) {
            if (v[i] > v[j]) dec[i] = max(dec[i], dec[j] + 1);
        }
    }

    int max_length = 0;
    for (int i = 1; i <= N; i++) {
        max_length = max(max_length, inc[i] + dec[i] - 1);
    }

    cout << max_length << endl;

    return 0;
}