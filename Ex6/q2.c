#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_STUDENTS 4

// Define semaphores
sem_t mutex;  // Controls access to the file
sem_t wrt;    // Controls writing to the file
int readers_count = 0;

void* student(void* student_id) {
    int id = *((int*)student_id);

    // Reading section
    printf("Student %d is reading.\n", id);
    // Lock mutex for accessing readers_count
    sem_wait(&mutex);
    readers_count++;
    if (readers_count == 1) {
        // If the first reader, lock writing to the file
        sem_wait(&wrt);
    }
    // Unlock mutex
    sem_post(&mutex);
    // Reading from the file
    printf("Student %d is reading the file content.\n", id);

    // Simulating reading time
    //sleep(rand() % 3);

    // Lock mutex for accessing readers_count
    sem_wait(&mutex);
    readers_count--;
    if (readers_count == 0) {
        // If the last reader, release writing to the file
        sem_post(&wrt);
    }
    // Unlock mutex
    sem_post(&mutex);

    // Writing section
    printf("Student %d is updating the file.\n", id);
    sem_wait(&wrt);
    // Writing to the file
    printf("Student %d is updating the file content.\n", id);
    // Simulating writing time
    //sleep(rand() % 3);
    sem_post(&wrt);

    pthread_exit(NULL);
}

int main() {
    pthread_t students[NUM_STUDENTS];
    int student_ids[NUM_STUDENTS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create threads for each student
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        student_ids[i] = i + 1;
        pthread_create(&students[i], NULL, student, &student_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        pthread_join(students[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
