#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findTime(int N, int K) {
    vector <int> visited(100001, -1);
    queue <int> q;
    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == K) return visited[current];

        vector <int> next_moves = {current - 1, current + 1, 2 * current};
        for (int i = 0; i < 3; i++) {
            if (next_moves[i] >= 0 && next_moves[i] <= 100000 && visited[next_moves[i]] == -1) {
                visited[next_moves[i]] = visited[current] + 1;
                q.push(next_moves[i]);
            }
        }
    }

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << findTime(N, K);

    return 0;
}