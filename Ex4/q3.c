#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void * fact(void *arg){
    int n = *((int *)arg);
    int facto = 1,i;
    for(i=2;i<=n;i++){
        facto = facto * i;
    }
    printf("Thread %lu : %d! is %d.\n",pthread_self(),n,facto);
    pthread_exit(NULL);
}


int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);

    pthread_t tid1;
    int rc1;

    rc1 = pthread_create(&tid1,NULL,fact,(void *)&n);
    if(rc1){
        printf("ERROR : return code for eveodd is %d",rc1);
        exit(1);
    }

    pthread_join(tid1,NULL);
    printf("All threads are terminated\n");
}
