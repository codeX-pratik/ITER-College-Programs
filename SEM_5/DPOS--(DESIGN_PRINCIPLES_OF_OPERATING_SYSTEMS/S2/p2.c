#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void decimalToBinary(int n, char* binary) {
    int index = 0;
    
    if (n == 0) {
        binary[index++] = '0';
    } else {
        while (n > 0) {
            binary[index++] = (n % 2) + '0';
            n /= 2;
        }
    }
    binary[index] = '\0';

    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
}

int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        char binary[32]; 
        decimalToBinary(n, binary);
        printf("Child Process: Binary representation of %d is %s\n", n, binary);
        exit(0); 
    } else {
        wait(NULL);
        
        char binary[32];
        decimalToBinary(n, binary);
        
        if (isPalindrome(binary)) {
            printf("Parent Process: The binary representation %s is a palindrome.\n", binary);
        } else {
            printf("Parent Process: The binary representation %s is not a palindrome.\n", binary);
        }
    }

    return 0;
}
