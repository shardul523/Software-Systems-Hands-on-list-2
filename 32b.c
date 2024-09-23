/*
============================================================================
Name : 32b.c

Author : Shardul Sisodiya

Description :
Write a program to implement semaphore to protect any critical section.
    b. Protect shared memory from concurrent write access

Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

union semaphore {
    int val;
};

struct ticketDetails {
    int tktNo;
};

int main() {
    key_t key = ftok("sharedMmyFile", 'O');
    int shm_id = shmget(key, sizeof(struct ticketDetails), IPC_CREAT | 0666);
    struct ticketDetails *ticket = (struct ticketDetails *)shmat(shm_id, NULL, 0);

    key_t sem_key = ftok("semaphoreFile", 'A');
    int semaphoreId = semget(sem_key, 1, IPC_CREAT | 0666);
    union semaphore sem_val = {144};
    semctl(semaphoreId, 0, SETVAL, sem_val);

    ticket->tktNo = 150;


    for (int i = 0; i < 5; i++) {
        struct sembuf operations = {0, -1, 0};
        semop(semaphoreId, &operations, 1);

        ticket->tktNo++;
        printf("Current ticket : %d\n", ticket->tktNo);

        operations.sem_op = 1;
        semop(semaphoreId, &operations, 1);
        sleep(1);
    }

    shmdt(ticket);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}

/*
OUTPUT
Current ticket : 151
Current ticket : 152
Current ticket : 153
Current ticket : 154
Current ticket : 155
*/
