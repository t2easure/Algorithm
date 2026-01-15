#include <stdio.h>
#include <math.h>

int countOpenWindows(int n) {
    return (int)sqrt(n);
}

int main() {
    int n;
    scanf("%d", &n);

    int result = countOpenWindows(n);
    printf("%d", result);

    return 0;
}
