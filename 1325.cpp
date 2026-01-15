#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector <vector<int>> computer(N + 1);
    vector <int> visited (N + 1, 0);
    computer[0] = {0};

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        computer[b].push_back(a);
    }

    int max = 0;
    queue <int> q;
    vector <int> result;
    for (int i = 1; i <= N; i++) {
        int number = 1;
        q.push(i);
        visited[i] = 1;

        while(!q.empty()) {
            int current = q.front();
            q.pop();
            number += 1;

            for (int j = 0; j < computer[current].size(); j++) {
                if (visited[computer[current][j]] == 0) {
                    q.push(computer[current][j]);
                    visited[computer[current][j]] = 1;
                }
            }
        }

        if (number > max) {
            max = number;
            result.clear();
            result.push_back(i);
        } else if (number == max) {
            result.push_back(i);
        }

        for (int j = 0; j < visited.size(); j++) visited[j] = 0;
    }

    for (int i = 0; i < result.size(); i++) 
        cout << result[i] << " ";

    return 0;
}