#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define ITERATIONS 20

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty_slots, full_slots;
pthread_mutex_t mutex;

void* producer(void* arg) {
    for (int i = 1; i <= ITERATIONS; i++) {
        sem_wait(&empty_slots);
        pthread_mutex_lock(&mutex);

        buffer[in] = i;
        printf("Producer produced: %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full_slots);

        usleep(100000);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    for (int i = 1; i <= ITERATIONS; i++) {
        sem_wait(&full_slots);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty_slots);

        usleep(150000);
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);
    pthread_mutex_destroy(&mutex);

    printf("Producer-Consumer program completed.\n");
    return 0;
}
