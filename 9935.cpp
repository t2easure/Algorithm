#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    string str;
    cin >> str;

    string boom;
    cin >> boom;

    deque <char> s2;

    for(int i = 0; i < str.length(); i++) {
        s2.push_back(str[i]);

        if (s2.size() >= boom.size()) {
            bool is_pattern = true;
            for(int j = 0; j < boom.size(); j++) {
                if (s2[s2.size() - boom.size() + j] != boom[j]) {
                    is_pattern = false;
                    break;
                }
            }
            if (is_pattern) {
                for (int j = 0; j < boom.size(); j++) {
                    s2.pop_back();
                }
            }
        }
    }

    if(s2.empty()) {
        cout << "FRULA\n";
    } else {
        for(int i = 0; i < s2.size(); i++) {
            cout << s2[i];
        }
    }

    return 0;
}
