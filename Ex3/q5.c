/*
An orphan process is a child process whose parent terminates before the child. The orphan process is then adopted by the init process (with PID 1).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Create the first child process
    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr,"fork error\n");
        exit(1);
    }

    if (child_pid > 0) {
        // Parent process
        printf("Parent Process (PID %d) with Parent (PPID %d)\n", getpid(), getppid());
        sleep(2);  // Allow time for child to become orphan
    
        // The parent process terminates, creating an orphan child
        printf("Parent Process (PID %d) terminating\n", getpid());
        exit(0);
    } else {
        // Child process
        printf("Child Process (PID %d) with Parent (PPID %d)\n", getpid(), getppid());
        //printf("Child PID kernel: %d",child_pid);

        // Simulate some work in the child process
        sleep(6);
        // The child process terminates
        
        //printf("Child PID kernel: %d",child_pid);
        printf("\nChild Process (PID %d) with Parent (PPID %d) terminating\n", getpid(), getppid());        
        exit(0);
    }

    return 0;
}

