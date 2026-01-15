#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    deque <int> num, num2;
    for(int i = 1; i <= N; i++){
        num.push_back(i);
    }

    int number = 1;
    while(!num.empty()){
        if(number != K){
            int number2 = num.front();
            num.pop_front();
            num.push_back(number2);
            number++;
        }
        else if(number == K){
            int number2 = num.front();
            num.pop_front();
            num2.push_back(number2);
            number = 1;
        }
    }

    cout << "<";
    while(!num2.empty()){
        cout << num2.front();
        num2.pop_front();
        if(num2.size() >= 1){
            cout << ", ";
        }
    }
    cout << ">";
}