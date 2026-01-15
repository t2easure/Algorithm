#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        vector <pair<int, int>> grades(N);
        for (int j = 0; j < N; j++) {
            cin >> grades[j].first >> grades[j].second;
        }

        sort(grades.begin(), grades.end(), compare);
        
        int count = 1;
        int best = grades[0].second;

        for (int i = 1; i < N; i++) {
            if (grades[i].second < best) {
                best = grades[i].second;
                count += 1;
            }
        }
        cout << count << endl;
    }

    return 0;
}