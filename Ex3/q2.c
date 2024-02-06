/*
    Write a c program to generate the given process tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char *argv[])
{
  	pid_t pid;
        int i, j; 
        int n_levels = atoi(argv[1]);
        int n_children = atoi(argv[2]);
 
        fprintf(stdout, "FIRST PROCESS: PID %d  PPID: %d\n", getpid(), getppid()); 
 
        for (i=0; i<n_levels; i++) {
 
	  for(j=0; j<n_children; j++) {
	    pid = fork();
	    if (pid == 0) { /* Child */
	      fprintf(stdout, "PID %d  PPID %d\n", getpid(), getppid());
	      break; /* The child exits from the inner loop */
	    }
	  }
	  if(pid!=0){ /* Father */
	    sleep(2); /* In order to leave active the father processes when "leaves"
                         processes terminate their execution. It is useful in order to not have
                         zombies processes when the last fprintf of this program is executed.
			 In this case the getppid() function prints the pid of the real father
                         and not the one of the process init/upstart */
	    exit(0); /* After the generation of n_children children the father ends */
	  }
 
	}
 
	sleep(1);
	fprintf(stdout, "LEAVES: PID %d  PPID %d\n", getpid(), getppid());
 
	return (0);
}
