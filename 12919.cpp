#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string S;

void solve(string t) {
    if (t == S) {
        cout << 1 << endl;
        exit(0);
    }

    if (t.length() <= S.length()) return;

    if (t.back() == 'A') {
        string temp = t;
        temp.pop_back();
        solve(temp);
    }

    if (t.front() == 'B') {
        string temp = t;
        reverse(temp.begin(), temp.end());
        temp.pop_back();
        solve(temp);
    }
}

int main() {
    string T;
    cin >> S >> T;

    solve(T);

    cout << 0 << endl;
    return 0;
}