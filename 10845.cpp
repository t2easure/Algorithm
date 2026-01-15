#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    queue <int> q;
    for(int i = 0; i < N; i++){
        string str;
        getline(cin, str);

        if(str.substr(0, 4) == "push"){
            q.push(stoi(str.substr(5)));
        }

        else if(str == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }
            else{
                cout << "-1\n";
            }
        }

        else if(str == "size"){
            cout << q.size() << "\n";
        }

        else if(str == "empty"){
            if(q.empty()){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }

        else if(str == "front"){
            if(!q.empty()){
                cout << q.front() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }

        else if(str == "back"){
            if(!q.empty()){
                cout << q.back() << "\n";
            }
            else{
                cout << "-1\n";
            }
        }
    }
}