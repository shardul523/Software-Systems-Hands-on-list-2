/*
============================================================================
Name : 32c.c

Author : Shardul Sisodiya

Description :
Write a program to implement semaphore to protect any critical section.
    c. Protect multiple pseudo resources (may be two) using counting semaphore

Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

union semun {
    int val;
};

struct ticketStruct {
    int tktNo;
};

void wait_semaphore(int semId) {
    struct sembuf op = {0, -1, 0};
    semop(semId, &op, 1);
}

void signal_semaphore(int semId) {
    struct sembuf op = {0, 1, 0};
    semop(semId, &op, 1);
}

int main() {
    key_t key = ftok("countingSem", 435);
    int semaphoreId = semget(key, 1, IPC_CREAT | 0666);
    union semun arg;
    arg.val = 2;

    semctl(semaphoreId, 0, SETVAL, arg);

    int fileDescript = open("database", O_CREAT | O_RDWR, 0666);
    struct ticketStruct tkt = {156};

    for (int i = 0; i < 5; i++) {
        wait_semaphore(semaphoreId);
        printf("Ticket Resource accessed by %d iteration.\n", i + 1);
        tkt.tktNo++;

        wait_semaphore(semaphoreId);
        printf("File Resource accessed by %d iteration.\n", i + 1);
        lseek(fileDescript, 0, SEEK_SET);
        write(fileDescript, &tkt, sizeof(tkt));

        signal_semaphore(semaphoreId);
        signal_semaphore(semaphoreId);
    }

    close(fileDescript);
    return 0;
}

/*
OUTPUT
Ticket Resource accessed by 1 iteration.
File Resource accessed by 1 iteration.
Ticket Resource accessed by 2 iteration.
File Resource accessed by 2 iteration.
Ticket Resource accessed by 3 iteration.
File Resource accessed by 3 iteration.
Ticket Resource accessed by 4 iteration.
File Resource accessed by 4 iteration.
Ticket Resource accessed by 5 iteration.
File Resource accessed by 5 iteration.
*/
