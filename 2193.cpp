#include <iostream>
#include <string>   
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N; 

    vector <pair<long long, long long>> v(N + 1, {0, 0});
    v[0] = {0, 0};
    v[1] = {0, 1};

    if (N == 1 || N == 2) {
        cout << 1 << endl;
        return 0;
    }
    
    v[2] = {1, 0};
    for (int i = 3; i <= N; i++) {
        v[i].first = v[i - 1].first + v[i - 2].first;
        v[i].second = v[i - 1].second + v[i - 2].second;
    }

    cout << v[N].first + v[N].second << endl;

    return 0;
}