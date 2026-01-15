#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector <int> v(8);

    for(int i = 0; i < 8; i++){
        cin >> v[i];

    }

    vector <int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector <int> v2 = {8, 7, 6, 5, 4, 3, 2, 1};
    
    if(v == v1){
        cout << "ascending\n";
    }
    else if(v == v2){
        cout << "descending\n";
    }
    else {
        cout << "mixed\n";
    }
}