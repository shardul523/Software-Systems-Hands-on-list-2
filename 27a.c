/*
============================================================================
Name : 27a.c

Author : Shardul Sisodiya

Description :
Write a program to receive messages from the message queue.
    a. with 0 as a flag

Date: 15th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define MESSAGE_SIZE 256

struct msgbuff {
    long mtype;
    char mtext[MESSAGE_SIZE];
};

int main(void) {
    struct msgbuff msgq;
    key_t key = ftok(".", 'a');
    int msg_rem = 1, bytes_read;
    char ch;

    if (key == -1) {
        perror("Could not generate unique key");
        exit(EXIT_FAILURE);
    }

    int msgqid = msgget(key, IPC_CREAT | 0666);

    if (msgqid == -1) {
        perror("Could not create message queue");
        exit(EXIT_FAILURE);
    }

    while (msg_rem) {
        bytes_read = msgrcv(msgqid, &msgq, MESSAGE_SIZE, 1, 0);
        if (bytes_read == -1) {
            perror("There was an error in reading the message");
            exit(EXIT_FAILURE);
        } else {
            printf("Message Read: %s\n", msgq.mtext);
            printf("Press Y to continue and N to exit\n");
            ch = getchar();
            if (ch == 'n' || ch == 'N')
                msg_rem = 0;
        }
    }

    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Message Read: New message
Press Y to continue and N to exit
n
============================================================================
*/
