#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector <string> number(N);

    for (int i = 0; i < N; i++) {
        cin >> number[i];
    }

    int max_length = 1;

    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) {
            for (int a = j + 1; a < M; a++) {
                if (number[i][j] == number[i][a]) {
                    int b = i + a - j;
                    if (b < N && number[b][j] == number[i][j] && number[b][a] == number[i][a]) {
                        if (max_length < a - j + 1) {
                            max_length = a - j + 1;
                        }
                    }
                    
                }
            }

        }
    }

    cout << max_length * max_length << endl;

    return 0;
}
