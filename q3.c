//Bubble Sort

#include <stdio.h>

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[],int n) {
    int swapped;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            swapped = 0;
            if(arr[j] < arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
                swapped = 1;
            }
            if(swapped == 0){
                break;
            }
        }
            
    }
}

int main() {
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Sorted array\n");
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
