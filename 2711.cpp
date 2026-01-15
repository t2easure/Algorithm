#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N;
        cin >> N;

        string str;
        cin >> str;

        string str1, str2;
        str1 = str.substr(0, N - 1);
        str2 = str.substr(N);
        str = str1 + str2;

        cout << str << "\n";
    }
}