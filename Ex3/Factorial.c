//Factorial 
#include <stdio.h>
int fact(int n);
int main() {
	int n;
	printf("Enter the number :\n");
	scanf("%d",&n);
	printf("Factorial = %d\n",fact(n));
}

int fact(int n) {
	if(n==1) {
		return 1;
	}
	int factN = fact(n-1) * n;
	return factN;
}
