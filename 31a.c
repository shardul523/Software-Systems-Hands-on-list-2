/*
============================================================================
Name : 31.c

Author : Shardul Sisodiya

Description :
Write a program to create a semaphore and initialize value to the semaphore.
    a. create a binary semaphore

Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

union semun {
    int val;
    struct semid_ds *buff;
    unsigned short *array;
} arg;

int main(void) {
    int semid;
    key_t key = ftok(".", 'A');

    if (key == -1) {
        perror("Could not create unique key");
        exit(EXIT_FAILURE);
    }

    semid = semget(key, 1, IPC_CREAT | 0744);

    if (semid == -1) {
        perror("Could not create semaphore");
        exit(EXIT_FAILURE);
    }

    arg.val = 1;

    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("Could not set the value of the semaphore");
        exit(EXIT_FAILURE);
    }

    printf("Created binary semaphore with id: %d\n", semid);
}

/*
============================================================================
OUTPUT:
Created binary semaphore with id: 0
============================================================================
*/
