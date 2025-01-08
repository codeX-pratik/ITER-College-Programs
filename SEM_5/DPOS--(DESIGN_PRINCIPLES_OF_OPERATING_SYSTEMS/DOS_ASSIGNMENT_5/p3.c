#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_A, sem_B;

void* print_A(void* arg) {
    for (int i = 0; i < 10; i++) { 
        sem_wait(&sem_A); 
        printf("A");
        fflush(stdout); 
        sem_post(&sem_B); 
    }
    pthread_exit(NULL);
}

void* print_B(void* arg) {
    for (int i = 0; i < 10; i++) { 
        sem_wait(&sem_B); 
        printf("B");
        fflush(stdout); 
        sem_post(&sem_A);
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&sem_A, 0, 1); 
    sem_init(&sem_B, 0, 0); 

    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, print_A, NULL);
    pthread_create(&threadB, NULL, print_B, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    sem_destroy(&sem_A);
    sem_destroy(&sem_B);

    printf("\nAlternating Characters program completed.\n");
    return 0;
}