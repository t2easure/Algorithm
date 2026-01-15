#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSorted(vector <char>&v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) return false;
    }
    int a = 0;
    int b = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') a += 1;
        else b += 1;
    }

    if (a < 1 || b < 2) return false;
    return true;
}

int main() {
    int L, C;
    cin >> L >> C;

    vector <char> chars(C);
    for (int i = 0; i < C; i++) cin >> chars[i];

    sort(chars.begin(), chars.end());

    vector<int> v(C, 0);
    fill(v.begin(), v.begin() + L, 1);

    do {
        vector <char> result;
        for (int i = 0; i < C; i++) 
            if (v[i] == 1) result.push_back(chars[i]);
        if (isSorted(result)) {
            for (int i = 0; i < result.size(); i++) cout << result[i];
            cout << endl;
        }
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}