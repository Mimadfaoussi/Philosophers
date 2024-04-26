#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
pthread_mutex_t forks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = *(int *)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", philosopher_id);
        usleep(1000000); // Simulate thinking

        // Pick up forks
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picked up fork %d (left).\n", philosopher_id, left_fork);
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d picked up fork %d (right).\n", philosopher_id, right_fork);

        // Eating
        printf("Philosopher %d is eating.\n", philosopher_id);
        usleep(1000000); // Simulate eating

        // Put down forks
        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d put down fork %d (right).\n", philosopher_id, right_fork);
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d put down fork %d (left).\n", philosopher_id, left_fork);
    }
    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    // Initialize mutexes (forks)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    // Wait for philosopher threads to finish (this will never happen in this example)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes (forks)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
