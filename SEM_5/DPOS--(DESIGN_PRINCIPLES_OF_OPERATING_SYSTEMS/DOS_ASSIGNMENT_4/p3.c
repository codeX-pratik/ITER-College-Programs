#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define FILE1 "file1.txt"
#define FILE2 "file2.txt"

void copy_file(const char *src, const char *dest) {
    FILE *src_file = fopen(src, "r");
    FILE *dest_file = fopen(dest, "w");

    if (!src_file || !dest_file) {
        perror("File open error");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_file)) {
        fputs(buffer, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void display_file(const char *file) {
    FILE *f = fopen(file, "r");
    if (!f) {
        perror("File open error");
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), f)) {
        printf("%s", buffer);
    }
    fclose(f);
}

void display_sorted_reverse(const char *file) {
    FILE *f = fopen(file, "r");
    if (!f) {
        perror("File open error");
        exit(1);
    }
    char *lines[100];
    int count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), f)) {
        lines[count] = strdup(buffer);
        count++;
    }
    fclose(f);
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]);
    }
}

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid1 == 0) {
        printf("First Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        copy_file(FILE1, FILE2);
        printf("First Child: Copied content from %s to %s\n", FILE1, FILE2);
        exit(0);
    }
    sleep(1);
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid2 == 0) {
        printf("Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Second Child: Displaying content of %s\n", FILE2);
        display_file(FILE2);
        exit(0);
    }
    sleep(1);

    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork failed");
        exit(1);
    }
    if (pid3 == 0) {
        printf("Third Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        printf("Third Child: Displaying sorted content of %s in reverse order\n", FILE2);
        display_sorted_reverse(FILE2);
        exit(0);
    }
    sleep(1);
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }
    printf("Parent Process: PID = %d\n", getpid());
    printf("Parent Process: All child processes have completed.\n");

    return 0;
}

/*

First Child: PID = 689, Parent PID = 688
First Child: Copied content from file1.txt to file2.txt
Second Child: PID = 690, Parent PID = 688
Second Child: Displaying content of file2.txt
A computer is a machine that can be programmed to automatically carry out sequences of arithmetic or logical operations (computation). Modern digital electronic computers can perform generic sets of operations known as programs. These programs enable computers to perform a wide range of tasks. The term computer system may refer to a nominally complete computer that includes the hardware, operating system, software, and peripheral equipment needed and used for full operation; or to a group of computers that are linked and function together, such as a computer network or computer cluster.
Third Child: PID = 691, Parent PID = 688
Third Child: Displaying sorted content of file2.txt in reverse order
A computer is a machine that can be programmed to automatically carry out sequences of arithmetic or logical operations (computation). Modern digital electronic computers can perform generic sets of operations known as programs. These programs enable computers to perform a wide range of tasks. The term computer system may refer to a nominally complete computer that includes the hardware, operating system, software, and peripheral equipment needed and used for full operation; or to a group of computers that are linked and function together, such as a computer network or computer cluster.
Parent Process: PID = 688
Parent Process: All child processes have completed.

*/




/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    FILE *dest = fopen(destination, "w");
    if (!src || !dest) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);
}

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void display_sorted_reverse(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    char lines[100][256];
    int count = 0;

    while (fgets(lines[count], sizeof(lines[count]), file)) {
        count++;
    }
    fclose(file);

    // Sort lines
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char temp[256];
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

    // Display sorted lines in reverse order
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
    }
}

int main() {
    pid_t pid1, pid2, pid3;

    // First child: Copy content of file1 to file2
    if ((pid1 = fork()) == 0) {
        printf("First child (PID: %d, Parent PID: %d): Copying file1 to file2...\n", getpid(), getppid());
        copy_file("file1.txt", "file2.txt");
        printf("First child: File copy completed.\n");
        exit(0);
    }

    sleep(1); // Delay for 1 second after creating the first child

    // Second child: Display content of file2
    if ((pid2 = fork()) == 0) {
        printf("Second child (PID: %d, Parent PID: %d): Displaying content of file2...\n", getpid(), getppid());
        display_file("file2.txt");
        printf("\nSecond child: Content displayed.\n");
        exit(0);
    }

    sleep(1); // Delay for 1 second after creating the second child

    // Third child: Display sorted content of file2 in reverse order
    if ((pid3 = fork()) == 0) {
        printf("Third child (PID: %d, Parent PID: %d): Displaying sorted content of file2 in reverse order...\n", getpid(), getppid());
        display_sorted_reverse("file2.txt");
        printf("\nThird child: Sorted content displayed.\n");
        exit(0);
    }

    sleep(1); // Delay for 1 second after creating the third child

    // Parent process: Wait for all child processes to complete
    printf("Parent process (PID: %d): Waiting for children to complete...\n", getpid());
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);
    printf("Parent process: All child processes completed. Exiting...\n");

    return 0;
}

*/