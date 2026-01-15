#include <stdio.h>

int main(){
    int n; 
    scanf("%d", &n);

    int num = 1;
    for(int i = 0; i < n; i ++){
        num *= 2;
    }
    printf("%d\n", num);

    return 0;
}