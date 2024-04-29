#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *strrev(void *arg){
    char *str = (char *)arg;
    int len = strlen(str);
    for(int i=0,j=len-1;i<=j;i++,j--){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("Thread %lu : Reversed String  is %s\n",pthread_self(),str);
    pthread_exit(NULL);
}

int main(){
    char c[100];
    printf("Enter the string : ");
    scanf("%s",&c);

    pthread_t tid1;
    int rc1;

    rc1 = pthread_create(&tid1,NULL,strrev,(void *)&c);
    if(rc1){
        printf("ERROR : return code for eveodd is %d",rc1);
        exit(1);
    }

    pthread_join(tid1,NULL);
    printf("All threads are terminated\n");
}
