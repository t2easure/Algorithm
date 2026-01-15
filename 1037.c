#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int a1;
    scanf("%d", &a1);

    int min = a1;
    int max = a1;

    for(int i = 0; i < N - 1; i ++){
        int n;
        scanf("%d", &n);
        if(n >= max){
            max = n;
        }
        if(n < min){
            min = n;
        }
    }

    printf("%d", max * min);
}