#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;

    int num = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-')){
            i += 1;
            num ++;
        }
        else if(str[i] == 'd' && ((str[i+1] == '-'))){
            i += 1;
            num++;
        }
        else if(str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '='){
            i += 2;
            num ++;
        }
        else if((str[i] == 'l' || str[i] == 'n') && str[i + 1] == 'j'){
            i += 1;
            num ++;
        }
        else if((str[i] == 's' || str[i] == 'z') && str[i + 1] == '='){
            i += 1;
            num ++;
        }
        else{
            num ++;
        }
    }

    cout << num;

    return 0;
}