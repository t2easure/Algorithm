#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;

    while(true){
        getline(cin, str);
        if(str == "."){
            break;
        }

        stack <char> s;
        bool isCorrect = true;

        for(int i = 0; i < str.length(); i ++){
            if(str[i] == '(' || str[i] == '['){
                s.push(str[i]);
            }
            else if(str[i] == ')' || str[i] == ']'){
                if(s.empty()){
                    isCorrect = false;
                    break;
                }
                
                if((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[')) {
                    s.pop();
                }
                else {
                    isCorrect = false;
                    break;
                }
            }
        }

        if(s.empty() && isCorrect){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
}

    