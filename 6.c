/*
============================================================================
Name : 6.c

Author : Shardul Sisodiya

Description : Write a simple program to create three threads.

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* threadExecFunc(void* arg) {
    int tid = *((int*) arg);

    printf("Executing function for thread %d\n", tid);

    sleep(tid);

    printf("Completed execution for thread %d\n", tid);

    return NULL;
}

int main(void) {
    pthread_t threads[3];
    int thread_ids[3];

    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, threadExecFunc, &thread_ids[i]) != 0) {
            perror("There was an error in creating a thread");
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("There was an error in executing the thread");
            return 1;
        }
    }

    printf("All the threads have completed their execution\n");
}

/*
============================================================================
OUTPUT:
Executing function for thread 3
Executing function for thread 1
Executing function for thread 2
Completed execution for thread 1
Completed execution for thread 2
Completed execution for thread 3
All the threads have completed their execution
============================================================================
*/
