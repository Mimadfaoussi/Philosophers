# Philosophers 42 

## Learning Objectives : 
In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes.

- I never thought philosophy would be so deadly - 

## Project Description :

Eat, Sleep, Spaghetti, repeat.

This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

### Overview : 

<ul>
<li>One or more philosophers sit at a round table. </li>
<li> There is a large bowl of spaghetti in the middle of the table.</li>
<li> The philosophers alternatively eat, think, or sleep.</li>
<li> While they are eating, they are not thinking nor sleeping;</li>
<li> of course, while sleeping, they are not eating nor thinking.</li>
<li> There are also forks on the table. There are as many forks as philosophers.</li>
<li> Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.</li>
<li>When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation. </li>
<li> Every philosopher needs to eat and should never starve.</li>
<li> Philosophers don’t speak with each other.</li>
<li> Philosophers don’t know if another philosopher is about to die.</li>
<li> No need to say that philosophers should avoid dying!</li>

## My Documentation : 

<p> In C programming, threads are independent sequences of execution that can run concurrently within a single process. They allow a program to perform multiple tasks simultaneously, utilizing the available CPU cores efficiently. Threads share the same memory space within the process, allowing them to communicate and coordinate with each other easily. </p>

#### thread creation : 

<p> we first need to include  pthread.h and we compile using -g -pthread flags  </p>

'''

void *thread_function(void *arg) {
    printf("This is a thread function.\n");
    return NULL;
}


int main() {
    pthread_t tid; // Thread ID
    int result;

    // Create a new thread
    result = pthread_create(&tid, NULL, thread_function, NULL);
    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(tid, NULL);

    printf("Thread has finished.\n");

    return 0;
}

'''

#### the difference between threads and processes : 

<p> Threads are smaller units of execution within a process, sharing the same memory space, unlike processes which have their own distinct memory spaces. </p>

#### Data races :
<p>
Data races occur in concurrent programming when two or more threads access a shared
variable concurrently . and at least one of the accesses is a write operation .<br>
If proper synchronization mechanisms are not used to coordinate access to the shared variable, data races can lead to unpredictable behavior and erroneous results.
</p>

#### Data races :

<p>
Mutexes are synchronization tools used in concurrent programming to prevent multi threads
from accessing shared ressources simultaneously . <br>
Using Mutexes in c :
</p>

''' 
#include <stdio.h>
#include <pthread.h>

// Shared resource
int shared_resource = 0;

// Mutex declaration
pthread_mutex_t mutex;

// Thread function
void *thread_function(void *arg) {
    // Lock the mutex before accessing the shared resource
    pthread_mutex_lock(&mutex);

    // Access and modify the shared resource
    shared_resource++;
    printf("Thread %ld incremented shared resource to: %d\n", (long)pthread_self(), shared_resource);

    // Unlock the mutex after accessing the shared resource
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t tid[5]; // Thread IDs
    int i;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create multiple threads
    for (i = 0; i < 5; i++) {
        pthread_create(&tid[i], NULL, thread_function, NULL);
    }

    // Join threads
    for (i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
'''

