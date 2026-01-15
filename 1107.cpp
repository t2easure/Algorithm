#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int M;
    cin >> M;

    vector <int> broken(M);
    for (int i = 0; i < M; i++) cin >> broken[i];

    if (N == 100) {
        cout << "0" << endl;
        return 0;
    }

    if (to_string(N).size() >= N - 100) {
        cout << N - 100 << endl;
        return 0;
    }
}