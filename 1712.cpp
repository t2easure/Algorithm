#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    
    long long A, B, C;
    ss >> A >> B >> C;

    if (B >= C) {
        cout << -1 << endl;
    } else {
        cout << (A / (C - B)) + 1 << endl;
    }

    return 0;
}
