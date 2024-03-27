#include <stdio.h>
#include <pthread.h>

int balance = 0;  // Shared balance
pthread_mutex_t lock;

void* account(void* args) {
    char* operation = (char*)args;
    if (operation[0] == 'd') {
        pthread_mutex_lock(&lock);
        balance += atoi(operation + 1);
        printf("Amount deposited: %d\n", atoi(operation + 1));
        pthread_mutex_unlock(&lock);
    } else if (operation[0] == 'w') {
        pthread_mutex_lock(&lock);
        if (balance >= atoi(operation + 1)) {
            balance -= atoi(operation + 1);
            printf("Amount withdrawn: %d\n", atoi(operation + 1));
        } else {
            printf("Insufficient balance for withdrawal\n");
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    pthread_mutex_init(&lock, NULL);

    char depositX[10], depositY[10], withdrawX[10], withdrawY[10];

    printf("Enter the amount X wants to deposit: ");
    scanf("%s", depositX);
    /*printf("Enter the amount Y wants to deposit: ");
    scanf("%s", depositY);
    printf("Enter the amount X wants to withdraw: ");
    scanf("%s", withdrawX);*/
    printf("Enter the amount Y wants to withdraw: ");
    scanf("%s", withdrawY);

    pthread_create(&tid1, NULL, account, (void*)depositX);
    //pthread_create(&tid2, NULL, account, (void*)depositY);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    //pthread_create(&tid1, NULL, account, (void*)withdrawX);
    pthread_create(&tid2, NULL, account, (void*)withdrawY);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&lock);
    printf("Final Balance : %d",balance);
    return 0;
}
