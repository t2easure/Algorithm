#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int n){
    if(l >= r) {
        printf("1 %d\n", n);
    }
    else if(s[l] != s[r]){
        printf("0 %d\n", n);
    }
    else{
        return recursion(s, l+1, r-1, n+1);
    }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1, 1);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char word[1000];
        scanf("%s", word);

        isPalindrome(word);
    }
}