#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;

    int num1 = 0; int num2 = 1;
    bool isFirst = true;

    char ch = str[0];
    for(int i = 0; i < str.length() - 1; i++){
        if(isFirst == true){
            if(str[i] != str[i + 1]){
                num1 ++;
                ch = str[i + 1];
                isFirst = false;
            }
        }

        else if(isFirst == false){
            if(str[i] != str[i + 1]){
                num2 ++;
                ch = str[i + 1];
                isFirst = true;
            }
        }   
    }

    cout << min(num1, num2) << "\n";
    
    return 0;
}