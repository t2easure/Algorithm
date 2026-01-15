#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector <pair<int, int>> schedule(N + 1);
    
    for (int i = 1; i <= N; i++) cin >> schedule[i].first >> schedule[i].second;

    vector <int> best(N + 2, 0);

    if (N == 1) {
        if (schedule[1].first > N) {
            cout << 0 << endl;
        } else {
            cout << schedule[1].second << endl;
        }

        return 0;
    }
 
    for (int i = N; i >= 1; i--) {
        if (schedule[i].first <= N - i + 1) {
            if (best[i + 1] < best[i + schedule[i].first] + schedule[i].second) {
                best[i] = best[i + schedule[i].first] + schedule[i].second;
            } else {
                best[i] = best[i + 1];
            }
        } else if (i + 1 <= N){
            best[i] = best[i + 1];
        }
    }

    cout << best[1];
    return 0;
}