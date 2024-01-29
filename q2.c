//Duplicates in array

#include <stdio.h>

int main() {
	int num;
	printf("Enter the size of the array: \n"); 
	scanf("%d",&num);
	
	int arr[num];
	printf("Enter the numbers\n");
	for(int i=0;i<num;i++) {
		scanf("%d",&arr[i]);
	}
	int k = 0;
	int dups[num];
	for(int i=0;i<num-1;i++) {
	    for(int j=i+1;j<num;j++) {
	        if(arr[i] == arr[j]) {
	            dups[k] = arr[i];
	            k++;
	        }
	    }
	}
	printf("Duplicate values are \n");
	for(int i=0;i<k;i++){
	    printf("%d\n",dups[i]);
	}
}
	

