#include <stdio.h>

int isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);

    while(n != 0){
        int number = 0;
        for(int i = n + 1; i <= 2 * n; i++){
            if(isPrime(i) == 1){
                number ++;
            }
        }

        printf("%d\n", number);
        scanf("%d", &n);
    }

    return 0;
}