#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int *num = (int *)arg;  // Cast the argument to an integer pointer
    printf("Thread argument: %d\n", *num);  // Access the integer value
    for (int i = 0; i < 5; i++) {
        printf("Thread: %d, Iteration: %d\n", pthread_self(), i);
        sleep(1);  // Simulate work done by the thread
    }
    pthread_exit(NULL);  // Terminate the thread explicitly
}

int main() {
    pthread_t thread_id;
    int argument = 10;  // Argument to be passed to the thread

    // Create a new thread
    if (pthread_create(&thread_id, NULL, thread_function, &argument) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    printf("Hello from main thread!\n");

    // Wait for the thread to terminate
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join failed");
        return 1;
    }

    printf("Thread joined successfully!\n");

    return 0;
}
