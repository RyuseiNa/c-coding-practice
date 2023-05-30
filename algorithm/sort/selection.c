#include <stdio.h>

void selectionSort(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        int minlen = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minlen]) {
                minlen = j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minlen];
        arr[minlen]= temp;
    }
}

int main() {
    int numbers[] = {5, 3, 8, 2, 1};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    printf("ソート前の配列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    selectionSort(numbers, n);
    printf("\nソート後の配列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
