/*
============================================================================
Name : 29.c

Author : Shardul Sisodiya

Description :
Write a program to remove the message queue.

Date: 15th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
    key_t key = ftok(".", 'a');
    int msqid;

    if (key == -1) {
        perror("Could not create a unique key");
        exit(EXIT_FAILURE);
    }

    msqid = msgget(key, IPC_CREAT | 0666);

    if (msqid == -1) {
        perror("Could not get message queue");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("Could not remove the message queue");
        exit(EXIT_FAILURE);
    }

    msqid = msgget(key, 0666);

    if (msqid == -1) {
        printf("Verification: Message Queue Removed\n");
    } else {
        printf("Error: Message queue was not removed\n");
    }

    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Verification: Message Queue Removed
============================================================================
*/
