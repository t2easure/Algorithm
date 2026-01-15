#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isTrue(string S1, string S2){
    return S1 < S2;
}

int main(){
    string S;
    cin >> S;

    vector <string> v;
    for(int i = 0; i < S.length(); i++){
        v.push_back(S.substr(i));
    }

    sort(v.begin(), v.end(), isTrue);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
}