#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getPriority (char op) {
    if (op == '/' || op == '*') return 2;
    if (op == '-' || op == '+') return 1;
    return 0;
}

int main() {
    string str;
    cin >> str;

    stack <char> s;
    for (int i = 0; i < str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') cout << str[i];
        else if (str[i] == '(') s.push(str[i]);
        else if (str[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && s.top() != '(' && getPriority(str[i]) <= getPriority(s.top())) {
                cout << s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}