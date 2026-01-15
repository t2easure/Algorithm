#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int i = 1;
    while(n >= i){
        int a, b;
        scanf("%d%d", &a, &b);

        int answer = 1;
        for(int j = 0; j < a; j ++){
            answer *= b - j;
            answer /= 1 + j;
        }
        
        printf("%d\n", answer);

        i += 1;
    }

    return 0;
}