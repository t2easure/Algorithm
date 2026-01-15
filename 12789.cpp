#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    int n, t, cnt = 1;

    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    while(n--){
        cin >> t;
        if(t == cnt)
            cnt ++;
        else
            s.push(t);
        while(!s.empty() && s.top() == cnt){
            s.pop();
            cnt++;
        }
    }

    if(s.empty()) cout << "Nice\n";
    else cout << "Sad\n";
}