#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to check if a number is odd or even
void *check_odd_even(void *num_ptr) {
    int num = *((int *)num_ptr); // Cast void pointer to int pointer and dereference it
    if (num % 2 == 0)
        printf("Thread %lu: %d is even.\n", pthread_self(), num);
    else
        printf("Thread %lu: %d is odd.\n", pthread_self(), num);
    pthread_exit(NULL);
}

// Function to check if a number is prime
void *check_prime(void *num_ptr) {
    int num = *((int *)num_ptr); // Cast void pointer to int pointer and dereference it
    int i;
    int is_prime = 1; // Assume the number is prime initially

    if (num <= 1) {
        is_prime = 0;
    } else {
        for (i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    if (is_prime)
        printf("Thread %lu: %d is a prime number.\n", pthread_self(), num);
    else
        printf("Thread %lu: %d is not a prime number.\n", pthread_self(), num);

    pthread_exit(NULL);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    pthread_t tid1, tid2;
    int rc1, rc2;

    // Create thread to check odd/even
    rc1 = pthread_create(&tid1, NULL, check_odd_even, (void *)&num);
    if (rc1) {
        printf("ERROR; return code from pthread_create() for odd/even check thread is %d\n", rc1);
        exit(-1);
    }

    // Create thread to check prime
    rc2 = pthread_create(&tid2, NULL, check_prime, (void *)&num);
    if (rc2) {
        printf("ERROR; return code from pthread_create() for prime check thread is %d\n", rc2);
        exit(-1);
    }

    // Wait for both threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_exit(NULL);
}
