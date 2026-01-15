#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool is_number(const string& s) {
    return !s.empty() && s.find_first_not_of("0123456789") == string::npos;
}

int main() {
    string line1, line2, line3;
    getline(cin, line1);
    getline(cin, line2);
    getline(cin, line3);
    
    int current_number = 0;
    if (is_number(line3)) {
        current_number = stoi(line3) + 1;
    } else if (is_number(line2)) {
        current_number = stoi(line2) + 2;
    } else if (is_number(line1)) {
        current_number = stoi(line1) + 3;
    } else {
        // If none are numbers, we can't determine the next sequence number based on input.
        // This condition should not occur given the problem statement.
        return 1;
    }
    
    if (current_number % 15 == 0) {
        cout << "FizzBuzz" << endl;
    } else if (current_number % 3 == 0) {
        cout << "Fizz" << endl;
    } else if (current_number % 5 == 0) {
        cout << "Buzz" << endl;
    } else {
        cout << current_number << endl;
    }

    return 0;
}
