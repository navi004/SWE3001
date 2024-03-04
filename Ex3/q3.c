/*
write a c program to illustrate process termination. 
    Create 5 processes among which one is the parent process and 4 child processes terminate all processes in the sequence given below : 
    (i) The parent process should terminate last after all the child processes 
    (ii) The fourth child process should terminate before the parent process. 
    (iii) The first child process terminates after the third child process. 
    (iv) The second child process should terminate before the first child process and after the third process 
    (v) The third child process should terminate first. 
    Print the termination in the sequence along with the ID of each process.
    */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void terminate(int id) {
    printf("Process %d terminated\n", id);
}

int main() {
    printf("Parent process ID: %d\n", getpid());

    // Creating the third child process (first to terminate)
    pid_t pid3 = fork();
    if (pid3 == 0) {
        // Third child process code
        terminate(3);
        exit(0);
    }

    // Creating the second child process (second to terminate)
    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Second child process code
        waitpid(pid3, NULL, 0); // Wait for the third child process to terminate
        terminate(2);
        exit(0);
    }

    // Creating the first child process (third to terminate)
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // First child process code
        terminate(1);
        exit(0);
    }

    // Creating the fourth child process (fourth to terminate)
    pid_t pid4 = fork();
    if (pid4 == 0) {
        // Fourth child process code
        waitpid(pid1, NULL, 0); // Waiting for the first child process to terminate
        terminate(4);
        exit(0);
    }

    // Parent process code
    waitpid(pid4, NULL, 0); // Waiting for the fourth child process to terminate
    terminate(getpid());

    return 0;
}


OR

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void terminate(int id,pid_t pid){
    printf("Child Process %d with pid %d is terminated\n",id,pid);
}

int main(){
    pid_t child_pids[4];
    printf("Parent Process pid : %d\n",getpid());
    for(int i=0;i<4;i++){
        pid_t child_pid = fork();

        if(child_pid < 0){
            fprintf(stderr,"Fork Failed\n");
            exit(EXIT_FAILURE);
        }
        if(child_pid == 0){
            printf("Child Process %d with pid : %d created\n",i+1,getpid());
            sleep(1);
            exit(EXIT_SUCCESS);
        }
        else{
            
            child_pids[i] = child_pid;
        }
    }
    waitpid(child_pids[2],NULL,0);
    terminate(3,child_pids[2]);

    waitpid(child_pids[1],NULL,0);
    terminate(2,child_pids[1]);

    waitpid(child_pids[0],NULL,0);
    terminate(1,child_pids[0]);

    waitpid(child_pids[3],NULL,0);
    terminate(4,child_pids[3]);

    waitpid(getpid(),NULL,0);
    printf("Parent process with pid %d is terminated",getpid());

    return 0;


}
