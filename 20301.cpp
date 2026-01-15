#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main(){
    int N, K, M;
    cin >> N >> K >> M;

    deque <int> num, num2;
    for(int i = 1; i <= N; i++){
        num. push_back(i);
    }

    int number = 1; int number24 = 0;
    while(!num.empty()){
        if(number != K){
            int number2 = num.front();
            num.pop_front();
            num.push_back(number2);
            number ++;
        }
        else if(number == K){
            int number2 = num.front();
            num.pop_front();
            num2.push_back(number2);
            number = 1;
            number24 ++;
        }
        if(number24 == M){
            for(int i = 0; i < num.size() / 2; i++){
                int a = num[i];
                num[i] = num[num.size() - i - 1];
                num[num.size() - i - 1] = a;
            }

            number24 = 0;
        }
    }

    for(int i = 0; i < num2.size(); i++){
        cout << num2[i] << "\n";
    }
}
