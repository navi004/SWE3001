

//upper to lower and vice versa
#include <stdio.h>
#include <string.h>

int main() {
	char a[100];
	printf("Enter the sentence:\n");
	scanf("%[^\n]%*c",a);
	
	printf("Orginal String:\n");
	for(int i=0;a[i] != '\0';i++) {
	printf("%c",a[i]);
	}
	
    printf("\n");
    	
    printf("String After Conversion:\n");
	for(int i=0;a[i] != '\0';i++) {
	    if(a[i] > 64 && a[i] < 91){
	        printf("%c",a[i] + 32);
	    }
	    else if(a[i] > 96 && a[i] < 123) {
	        printf("%c",a[i]-32);
	    }
	    else {
	        printf("%c",a[i]);
	    }
	}

}	


OR


#include <stdio.h>

int main(){
    char str[100];
    printf("Enter the sentence : ");
    //fgets(str,100,stdin);
    scanf("%[^\n]%*c",str);
    
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>= 'A' && str[i] <= 'Z'){
            printf("%c",str[i]+32);
        }
        else if(str[i]> 'a' && str[i]<= 'z'){
            printf("%c",str[i]-32);
        }
        else {
            printf("%c",str[i]);
        }
    }
    return 0;
}
