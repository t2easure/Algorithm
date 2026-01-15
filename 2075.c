#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reheapDown(int* arr, int start, int end) {
    int child = 2 * start + 1;
    while (child <= end) {
        if (child + 1 <= end && arr[child + 1] < arr[child])
            child += 1;
        if (arr[child] < arr[start]) {
            swap(&arr[start], &arr[child]);
            start = child;
            child = 2 * start + 1;
        } else {
            break;
        }
    }
}

void buildHeap(int* heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        reheapDown(heap, i, size - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* minHeap = (int*)malloc(n * n * sizeof(int));
    if (!minHeap) return -1;

    for (int i = 0; i < n * n; i++) {
        scanf("%d", &minHeap[i]);
    }

    buildHeap(minHeap, n);

    for (int i = n; i < n * n; i++) {
        if (minHeap[i] > minHeap[0]) {
            minHeap[0] = minHeap[i];
            reheapDown(minHeap, 0, n - 1);
        } // 최소 힙이라서 제거하면 더 큰 수가 들어옴
        // n번째 수가 가장 앞에 옴(n개 중에서는 가장 작기 때문에)
    }

    printf("%d", minHeap[0]);

    return 0;
}