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



/*

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();  // Create a child process

    if (pid == 0) {  // Child process
        while (1) {
            printf("Child process: PID = %d\n", getpid());
            sleep(1);  // Sleep for 1 second to prevent overloading the terminal
        }
    } else if (pid > 0) {  // Parent process
        while (1) {
            printf("Parent process: PID = %d\n", getpid());
            sleep(1);  // Sleep for 1 second to prevent overloading the terminal
        }
    } else {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    return 0;
}



*/