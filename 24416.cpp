#include <iostream>
#include <vector>

using namespace std;

int number2 = 0;

int fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

void fibonacci(int n){
    vector <int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
        number2 ++;
    }
}

int main(){
    int n;
    cin >> n;

    number2 = 0;
    
    int result1 = fib(n);
    fibonacci(n);

    cout << result1 << " " << number2;
}