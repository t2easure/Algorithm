#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    int num = 0;
    while (B > A) {
        if (B % 10 == 1) {
            B /= 10;
            num += 1;
        } else {
            if (B % 2 == 0) {
                B /= 2;
                num += 1;
            } else {
                num = -2;
                break;
            }
        }
    }

    if (B < A) cout << -1 << endl;
    else cout << num + 1 << endl; 

    return 0;
}

/*BFS로 푸는 방법
int main() {
    long long A, B;
    cin >> A >> B;

    queue <pair<long long, int>> q;
    q.push({A, 1}); -> (현재 값, 연산 횟수)

    while (!q.empty()) {
        long long curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (curr == B) {
            cout << cnt << endl;
            return 0;   
        }

        if (curr * 2 <= B) q.push({curr * 2, cnt + 1});
        if (curr * 10 + 1 <= B) q.push({curr * 10 + 1, cnt + 1});
    }

    cout << -1 << endl;
    return 0;
}*/