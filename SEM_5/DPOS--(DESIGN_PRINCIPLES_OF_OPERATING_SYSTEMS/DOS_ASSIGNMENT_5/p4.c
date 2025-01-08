#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_A, sem_B;

void* countdown(void* arg) {
    for (int i = 10; i >= 1; i--) {
        sem_wait(&sem_A); 
        printf("Thread A (Countdown): %d\n", i);
        sem_post(&sem_B); 
    }
    pthread_exit(NULL);
}

void* countup(void* arg) {
    for (int i = 1; i <= 10; i++) {
        sem_wait(&sem_B); 
        printf("Thread B (Countup): %d\n", i);
        sem_post(&sem_A); 
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&sem_A, 0, 1); 
    sem_init(&sem_B, 0, 0); 

    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, countdown, NULL);
    pthread_create(&threadB, NULL, countup, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    sem_destroy(&sem_A);
    sem_destroy(&sem_B);

    printf("Countdown and Countup program completed.\n");
    return 0;
}