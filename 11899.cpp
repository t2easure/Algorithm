#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(){
    string str;
    cin >> str;

    stack <char> s;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            s.push(str[i]);
        }

        else if(str[i] == ')'){
            if(!s.empty() && s.top() == '('){
                s.pop();
            }
            else{
                s.push(str[i]);
            }
        }
    }

    vector <char> v2;
    if(s.empty()){
        cout << 0;
    }
    else{
        cout << s.size();
    }
}