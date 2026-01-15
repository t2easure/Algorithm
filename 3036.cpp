#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int getGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int N;
    cin >> N;
    vector <int> v(N);

    for(int i = 0; i < N; i++){
        cin >> v[i];
    } 

    int num = v[0];

    for(int j = 1; j < v.size(); j ++){
        if(num % v[j] == 0){
            cout << num/v[j] << '/' << 1 << "\n";
        }
        else if(v[j] % num == 0){
            cout << 1 << "/" << v[j]/num << "\n";
        }
        else if(num % v[j] != 0){
            cout << num/getGCD(num, v[j]) << "/" << v[j]/getGCD(num, v[j]) << "\n";
        }
    }
}