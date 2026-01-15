#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    int line = 1;
    
    while(num > line){
        num -= line;
        line += 1;
    }

    int a;
    int b;

    if(line % 2 == 0){
        a = num;
        b = line - num + 1;
    }
    else if(line % 2 == 1){
        a = line - num + 1;
        b = num;
    }

    printf("%d/%d", a, b);
}