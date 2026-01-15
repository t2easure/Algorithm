#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;
    cin >> N >> X;

    vector <int> visitors;
    for (int i = 0; i < N; i++) {
        int visitor;
        cin >> visitor;
        visitors.push_back(visitor);
    }

    vector <int> accumul(N, 0);
    for (int i = 0; i < X; i++) {
        accumul[X - 1] += visitors[i];
    }
    for (int i = X; i < N; i++) {
        accumul[i] = accumul[i - 1] + visitors[i] - visitors[i - X];
    }

    int max = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (accumul[i] > max) {
            max = accumul[i];
            cnt = 1;
        } else if (accumul[i] == max) {
            cnt += 1;
        }
    }

    if (max == 0) 
        cout << "SAD" << '\n';
    else
        cout << max << '\n' << cnt << '\n';

    return 0;
}