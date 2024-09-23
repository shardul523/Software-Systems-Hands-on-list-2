/*
============================================================================
Name : 32d.c

Author : Shardul Sisodiya

Description :
Write a program to implement semaphore to protect any critical section.
    d. Remove the created semaphore

Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semaphoreKey", 0);

    int semaphoreId = semget(key, 1, 0);

    semctl(semaphoreId, 0, IPC_RMID);
    return 0;
}
