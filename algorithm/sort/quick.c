#include <stdio.h>

void quickSort(int arr[],int min,int high){
    if(min<high){
        int partition = 
    }


}

int main(){
    int numbers[] = {5,11,1,9,20,3,};
    int len = sizeof(numbers)/sizeof(numbers[0]);

    printf("ソート前：");
    for(int i=0;i<len;i++){
        printf("%d",numbers[i]);
    }

    quickSort(numbers,len);
    printf("\nソート後");
    for(int i=0;i<len;i++){
        printf("%d",numbers[i]);
    }
}