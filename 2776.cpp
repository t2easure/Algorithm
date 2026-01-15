#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N, M;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        vector <int> book1(N, 0);
        for (int j = 0; j < N; j++) 
            cin >> book1[j];
        cin >> M;
        vector <int> book2(M, 0);
        for (int j = 0; j < M; j++)
            cin >> book2[j];

        sort(book1.begin(), book1.end());

        for (int j = 0; j < M; j++) {
            bool is_in = binary_search(book1.begin(), book1.end(), book2[j]);
            if (is_in) cout << 1 << "\n";
            else cout << 0 << "\n";
        } 
    }

    return 0;
}