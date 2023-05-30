#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int pos = i;
        while (pos!=0&&arr[pos-1]>arr[pos])
        {
            int temp=arr[pos-1];
            arr[pos-1] = arr[pos];
            arr[pos] = temp;
            pos--;
        }
    }
}

int main(){
    int array []= {1,2,3,10,20,9,2,4,};
    int len = sizeof(array)/sizeof(array[0]);
     
    printf("ソート前：");
    for(int i=0;i<len;i++){
        printf("%d",array[i]);
    }

    insertionSort(array,len);
    printf("\nソート後：");
    for(int i=0;i<len;i++){
        printf("%d",array[i]);
    }
    printf("\n");
    printf("%d\n",len);
    return 0;
}