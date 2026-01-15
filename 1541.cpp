#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    string temp = "";
    bool isSubtracting = false;
    int number = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp += str[i];
        } else {
            if (temp != "") {
                int num = stoi(temp);
                if (isSubtracting) 
                    number -= num;
                else number += num;

                temp = "";
            }
            if (str[i] == '-') 
                isSubtracting = true;
        }
    }
    
    if (isSubtracting == false) {
        number += stoi(temp);
    } else number -= stoi(temp);

    cout << number << "\n";

    return 0;
}