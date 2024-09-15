/*
============================================================================
Name : 26.c

Author : Shardul Sisodiya

Description :
Write a program to send messages to the message queue. Check $ipcs -q

Date: 15th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[256];
};

int main(void) {
    struct msgbuf msg;
    int key = ftok(".", 'a'), msqid;
    int to_continue = 1;

    if (key == -1) {
        perror("Could not create a unique key");
        return 1;
    }

    msqid = msgget(key, IPC_CREAT | 0666);

    if (msqid == -1) {
        perror("Could not create message queue");
        exit(EXIT_FAILURE);
    }

    msg.mtype = 1;

    while (to_continue) {
        printf("Enter the message to send. Type \"exit\" to end:\n");
        fgets(msg.mtext, sizeof(msg.mtext) - 1, stdin);
        msg.mtext[strlen(msg.mtext) - 1] = 0;
        // printf("%s\n", msg.mtext);
        if (strcmp(msg.mtext, "exit") == 0) {
            to_continue = 0;
        } else if (msgsnd(msqid, &msg, strlen(msg.mtext) + 1, 0) == -1) {
            perror("Could not send the message to the Message Queue");
            exit(EXIT_FAILURE);
        } else {
            printf("Message sent successfully\n");
        }
    }

    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Enter the message to send. Type "exit" to end:
New message
Message sent successfully
Enter the message to send. Type "exit" to end:
exit
============================================================================
*/
