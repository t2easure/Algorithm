#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector <int> visited(100001, -1);
vector <int> ways(100001, 0);

int findTime(int N, int K) {
    queue <int> q;
    q.push(N);
    visited[N] = 0;
    ways[N] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == K) return visited[current];
        vector <int> next_moves = {current + 1, current - 1, current * 2};
        for (int i = 0; i < 3; i++) {
            if (next_moves[i] >=0 && next_moves[i] <= 100000) {
                if (visited[next_moves[i]] == -1) {
                    visited[next_moves[i]] = visited[current] + 1;
                    ways[next_moves[i]] = ways[current];
                    q.push(next_moves[i]);
                } else if (visited[next_moves[i]] == visited[current] + 1) ways[next_moves[i]] += ways[current];
            }
        }
    }

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << findTime(N, K) << endl;
    cout << ways[K] << endl;

    return 0;
}