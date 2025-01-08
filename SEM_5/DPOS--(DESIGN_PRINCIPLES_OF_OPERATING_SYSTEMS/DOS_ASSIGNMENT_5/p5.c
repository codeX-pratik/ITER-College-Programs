#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_A, sem_B, sem_C;

int current_number = 1;

void* thread_A(void* arg) {
    while (current_number <= 20) {
        sem_wait(&sem_A); 
        if (current_number <= 20) {
            printf("A%d\n", current_number);
            current_number++;
        }
        sem_post(&sem_B); 
    }
    pthread_exit(NULL);
}

void* thread_B(void* arg) {
    while (current_number <= 20) {
        sem_wait(&sem_B); 
        if (current_number <= 20) {
            printf("B%d\n", current_number);
            current_number++;
        }
        sem_post(&sem_C); 
    }
    pthread_exit(NULL);
}

void* thread_C(void* arg) {
    while (current_number <= 20) {
        sem_wait(&sem_C); 
        if (current_number <= 20) {
            printf("C%d\n", current_number);
            current_number++;
        }
        sem_post(&sem_A); 
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&sem_A, 0, 1); 
    sem_init(&sem_B, 0, 0); 
    sem_init(&sem_C, 0, 0); 

    pthread_t threadA, threadB, threadC;
    pthread_create(&threadA, NULL, thread_A, NULL);
    pthread_create(&threadB, NULL, thread_B, NULL);
    pthread_create(&threadC, NULL, thread_C, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
    sem_destroy(&sem_C);

    printf("Sequence printing program completed.\n");
    return 0;
}