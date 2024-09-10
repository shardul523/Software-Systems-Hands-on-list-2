/*
============================================================================
Name : 7.c

Author : Shardul Sisodiya

Description : Write a simple program to print the created thread ids.

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* threadExecFunction(void* arg) {
    int tc = *((int*)arg);
    printf("Executing thread number %d\n", tc);
    return NULL;
}

int main(void) {
    pthread_t threads[3];
    int thread_nums[3];

    for (int i = 0; i < 3; i++) {
        thread_nums[i] = i + 1;
        if (pthread_create(&threads[i], NULL, threadExecFunction, &thread_nums[i]) != 0) {
            perror("Could not create the thread");
            return 1;
        }
        printf("Thread %d ID: %lu\n", thread_nums[i], threads[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Error in executing the thread");
            return 1;
        }
    }

    printf("All threads completed executing\n");
}

/*
============================================================================
OUTPUT:
Thread 1 ID: 133798240978624
Executing thread number 1
Thread 2 ID: 133798230492864
Executing thread number 2
Thread 3 ID: 133798220007104
Executing thread number 3
All threads completed executing
============================================================================
*/
