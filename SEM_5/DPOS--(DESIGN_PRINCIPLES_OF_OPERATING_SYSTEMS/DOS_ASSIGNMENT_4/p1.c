#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
        sleep(5); 
        printf("Child process exiting.\n");
        exit(0);
    } else {
        printf("Parent: PID = %d\n", getpid());
        wait(NULL);
        printf("Child process completed. Parent exiting.\n");
    }

    return 0;
}


/*

Parent: PID = 564
Child: PID = 565
Child process exiting.
Child process completed. Parent exiting.

*/