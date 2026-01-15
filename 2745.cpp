#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string N;
    int B;
    cin >> N >> B;

    int number = 0;

    for(int i = 0; i < N.length(); i++){
        if(N[i] >= '0' && N[i] <= '9'){
            number = number * B + (N[i] - '0');
        }
        else{
            number = number * B + (N[i] - 'A' + 10);
        }
    }

    cout << number;

    return 0;
}