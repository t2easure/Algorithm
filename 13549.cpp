#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    if (N >= K) {
        cout << N - K << endl;
        return 0;
    }

    vector<int> dist(100001, numeric_limits<int>::max());
    dist[N] = 0;
    queue <int> q;
    q.push(N);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int arr[3] = {current + 1, current - 1, current * 2};
        int second[3] = {1, 1, 0};

        for (int i = 0; i < 3; i++) {
            int distance = arr[i];
            if (distance >= 0 && distance <= 100000) {
                if (dist[distance] > dist[current] + second[i]) {
                    dist[distance] = dist[current] + second[i];
                    q.push(distance);
                }
            }
        }
    }

    cout << dist[K] << endl;

    return 0;
}