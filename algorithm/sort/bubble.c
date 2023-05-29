#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numbers[] = {5, 3, 8, 2, 1};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    printf("ソート前の配列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    bubbleSort(numbers, n);
    printf("\nソート後の配列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}
