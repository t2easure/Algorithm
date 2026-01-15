#include <stdio.h>

int Is_Prime(int n, int prime[]) {
    for (int i = 0; i <= n; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    int max_n = 0;
    int arr[T];
    for (int i = 0; i < T; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max_n) {
            max_n = arr[i];
        }
    }

    int prime[max_n + 1];
    Is_Prime(max_n, prime);

    for (int i = 0; i < T; i++) {
        int count = 0;
        for (int j = 2; j <= arr[i] / 2; j++) {
            if (prime[j] && prime[arr[i] - j]) {
                count += 1;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}