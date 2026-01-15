#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        string str;
        cin >> str;

        string p;
        cin >> p;

        int length = 0;
        while(str.find(p) != string::npos){
            str.erase(str.find(p), p.length());
            length += 1;
        }

        cout << length + str.length() << "\n";
    }

    return 0;
}