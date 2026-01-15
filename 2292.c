#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int room = 1;
    int max_in_layer = 1;    
    while (N > max_in_layer) {
        max_in_layer += 6 * room;
        room += 1;
    }

    printf("%d", room);

    return 0;
}