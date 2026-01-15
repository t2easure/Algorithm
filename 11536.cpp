#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool IncreaseCompare(string a, string b){
    return a < b;
}

bool DecreaseCompare(string a, string b){
    return a > b;
}

int main(){
    int N;
    cin >> N;

    vector <string> name(N);
    for(int i = 0; i < N; i++){
        cin >> name[i];
    }

    vector <string> name1(name.begin(), name.end());
    vector <string> name2(name.begin(), name.end());

    sort(name1.begin(), name1.end(), IncreaseCompare);
    sort(name2.begin(), name2.end(), DecreaseCompare);

    if(name == name1){
        cout << "INCREASING\n";
    }
    else if(name == name2){
        cout << "DECREASING\n";
    }
    else{
        cout << "NEITHER\n";
    }

    return 0;
}