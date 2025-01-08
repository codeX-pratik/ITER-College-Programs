#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem_A, sem_B, sem_C;

void* thread_A(void* arg) {
    for (int i = 3; i <= 20; i += 3) {
        sem_wait(&sem_A); 
        printf("A%d\n", i);
        sem_post(&sem_B); 
    }
    return NULL;
}

void* thread_B(void* arg) {
    for (int i = 2; i <= 20; i += 3) {
        sem_wait(&sem_B); 
        printf("B%d\n", i);
        sem_post(&sem_C); 
    }
    return NULL;
}

void* thread_C(void* arg) {
    for (int i = 1; i <= 20; i += 3) {
        sem_wait(&sem_C); 
        printf("C%d\n", i);
        sem_post(&sem_A); 
    }
    return NULL;
}

int main() {
    sem_init(&sem_A, 0, 1);
    sem_init(&sem_B, 0, 0);
    sem_init(&sem_C, 0, 0);

    pthread_t thread1, thread2, thread3;

    // Create threads
    pthread_create(&thread1, NULL, thread_A, NULL);
    pthread_create(&thread2, NULL, thread_B, NULL);
    pthread_create(&thread3, NULL, thread_C, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
    sem_destroy(&sem_C);

    return 0;
}
