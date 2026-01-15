#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    deque <bool> isPrime(N + 1, true);

    int count = 0;
    int PrintNum = 0;

    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= N; i++){
        if(isPrime[i] == 1){
            count ++;
            if(count == K){
                PrintNum = i;
                break;
            }

            for(int j = i * 2; j <= N; j += i){
                if(isPrime[j] == 1){
                    isPrime[j] = false;
                    count ++;
                    if(count == K){
                        PrintNum = j;
                        break;
                    }
                }
            }
        }
    }

    cout << PrintNum;

    return 0;
}