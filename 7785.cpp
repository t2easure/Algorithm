#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string, hash<string>> presentEmployees;

    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;

        if (state == "enter") {
            presentEmployees.insert(name);
        } else if (state == "leave") {
            presentEmployees.erase(name);
        }
    }

    vector<string> sortedEmployee(presentEmployees.begin(), presentEmployees.end());

    sort(sortedEmployee.begin(), sortedEmployee.end(), greater<string>());

    for (const string& emp : sortedEmployee) {
        cout << emp << '\n';
    }

    return 0;
}
