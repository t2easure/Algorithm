#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    if(N == 1){
        cout << "CY";
    }
    else if(N % 2 == 0){
        cout << "SK";
    }
    else {
        cout << "CY";
    }
}