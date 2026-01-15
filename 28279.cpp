#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    cin.ignore();

    deque <int> d;
    for(int i = 0; i < N; i++){
        string command;
        getline(cin, command);

        if(command[0] == '1'){
            int num = stoi(command.substr(2));
            d.push_front(num);
        }
        else if(command[0] == '2'){
            int num = stoi(command.substr(2));
            d.push_back(num);
        }
        else if(command[0] == '3'){
            if(!d.empty()){
                cout << d.front() << "\n";
                d.pop_front();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(command[0] == '4'){
            if(!d.empty()){
                cout << d.back() << "\n";
                d.pop_back();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(command[0] == '5'){
            cout << d.size() << "\n";
        }
        else if(command[0] == '6'){
            if(!d.empty()){
                cout << "0\n";
            }
            else{
                cout << "1\n";
            }
        }
        else if(command[0] == '7'){
            if(!d.empty()){
                cout << d.front() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
        else if(command[0] == '8'){
            if(!d.empty()){
                cout << d.back() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
    }
}