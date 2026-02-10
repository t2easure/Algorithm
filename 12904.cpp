#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    while (str1.length() < str2.length()) {
        char last = str2[str2.length() -1];

        if (last == 'B') {
            str2.pop_back();
            reverse(str2.begin(), str2.end());
        } else {
            str2.pop_back();
        }
    }

    if (str1 == str2) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}