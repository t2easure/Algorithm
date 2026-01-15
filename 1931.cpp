#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;

    vector <pair<int, int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    int count = 0;
    int last_end_time = 0;

    for (int i = 0; i < N; i++) {
        if (v[i].first >= last_end_time) {
            last_end_time = v[i].second;
            count += 1;
        }
    }

    cout << count << endl;
    
    return 0;
}