//Bubble Sort

#include <stdio.h>

int main() {
	int n;
	printf("Enter the number of elemennts : ");

	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	printf("The array before arrange : ");
	for(int i =0;i<n;i++) {

		printf("%d ",arr[i]);
	}
	
	printf("\n");
	for(int i =0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(arr[i+1] < arr[i]) {

				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	printf("After Ordering\n");
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}
