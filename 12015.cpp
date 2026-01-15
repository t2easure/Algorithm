#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector <int> numbers(N);
    vector <int> lis;

    for (int i = 0; i < N; i++) cin >> numbers[i];

    for (int i = 0; i < N; i++) {
        int current = numbers[i];
        int start = 0;
        int end = lis.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (current <= lis[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        if (start == lis.size()) lis.push_back(current);
        else lis[start] = current;
    }

    cout << lis.size() << "\n";

    return 0;
}