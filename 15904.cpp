#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    getline(cin, str);

    string target = "UCPC";
    int targetIndex = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == target[targetIndex]){
            targetIndex ++;
        }
        if(targetIndex == target.length()){
            break;
        }
    }

    if(targetIndex == target.length()){
        cout << "I love UCPC\n";
    }
    else{
        cout << "I hate UCPC\n";
    }

    return 0;
}