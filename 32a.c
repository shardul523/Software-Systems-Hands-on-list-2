/*
============================================================================
Name : 32a.c

Author : Shardul Sisodiya

Description :
Write a program to implement semaphore to protect any critical section.
    a. Rewrite the ticket number creation program using semaphore

Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

struct ticket {
    int number;
};

int main() {
    key_t key = ftok("tktFile", 'O');
    int semaphoreId = semget(key, 1, IPC_CREAT | 0666);
    union semun sem_val;
    sem_val.val = 1;
    semctl(semaphoreId, 0, SETVAL, sem_val);

    int file = open("ticketdb", O_CREAT | O_RDWR, 0666);
    struct ticket t = {144};

    struct sembuf operations = {0, -1, 0};
    semop(semaphoreId, &operations, 1);

    t.number++;
    lseek(file, 0, SEEK_SET);
    write(file, &t, sizeof(t));
    close(file);

    operations.sem_op = 1;
    semop(semaphoreId, &operations, 1);

    return 0;
}
