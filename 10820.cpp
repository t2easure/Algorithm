#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int main(){
    string str;
    while(getline(cin, str)){
        int a =0 , b= 0, c= 0, d=0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] >= 65 && str[i] <= 90){
                a += 1;
            }
            else if(str[i] >= 97 && str[i] <= 122){
                b += 1;
            }
            else if(str[i] >= '0' && str[i] <= '9'){
                c += 1;
            }
            else if(str[i] == ' '){
                d += 1;
            }
        }

        cout << b << " " << a << " " << c << " " << d << "\n";
    } 
}
    