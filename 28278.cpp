#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    stack <int> s;

    for(int i = 0; i < N; i++){
        string str;
        getline(cin, str);
        
        if(str[0] == '1'){
            int num = stoi(str.substr(2));
            s.push(num);
        }
        else if(str[0] == '2'){
            if(!s.empty()){
                cout << s.top() << "\n";
                s.pop();
            }
            else{
                cout << "-1\n";
            }
        }
        else if(str[0] == '3'){
            cout << s.size() << "\n";
        }
        else if(str[0] == '4'){
            if(s.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(str[0] == '5'){
            if(!s.empty()){
                cout << s.top() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
    }

    return 0;
}
