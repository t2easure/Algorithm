#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    deque<int> q;

    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    queue<int> q1;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        q1.push(num);
    }

    int numbering = 0;

    while (!q1.empty()) {
        int target = q1.front();
        int index = 0;
        for (int i = 0; i < q.size(); i++) {
            if (q[i] == target) {
                index = i;
                break;
            }
        }

        while (q.front() != target) {
            if (index < q.size() - index) {
                int number = q.front();
                q.pop_front();
                q.push_back(number);
            } else {
                int number = q.back();
                q.pop_back();
                q.push_front(number);
            }
            numbering++;
        }

        q.pop_front();
        q1.pop();
    }

    cout << numbering << endl;

    return 0;
}
