#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int mode(int arr[], int n) {
    int count[8001] = {0}; // -4000부터 4000까지의 빈도수를 저장하기 위한 배열
    int maxCount = 0;
    int mode = 0;

    for (int i = 0; i < n; i++) {
        count[arr[i] + 4000]++; // 음수를 양수 인덱스로 변환하여 빈도수 증가
    }

    for (int i = 0; i < 8001; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mode = i - 4000; // 양수 인덱스를 다시 음수로 변환하여 최빈값 저장
        }
    }

    int secondMode = 0;
    int maxModeCount = 0;
    for (int i = 0; i < 8001; i++) {
        if (count[i] == maxCount) {
            if (maxModeCount == 0) {
                secondMode = i - 4000;
                maxModeCount++;
            } else {
                secondMode = i - 4000;
                break;
            }
        }
    }

    return secondMode;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[500000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // 산술평균을 계산한 후 반올림하여 출력
    double average = (double)sum / n;
    if (average > -0.5 && average < 0) {
        printf("%d\n", 0);
    } else {
        printf("%.0f\n", round(average)); // 소수점 이하를 버리고 정수로 출력
    }

    // 중앙값 출력
    qsort(arr, n, sizeof(int), compare);
    printf("%d\n", arr[n / 2]);

    // 최빈값 출력
    printf("%d\n", mode(arr, n));

    // 범위 출력
    printf("%d\n", arr[n - 1] - arr[0]);

    return 0;
}
