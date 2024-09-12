/*
============================================================================
Name : 15.c

Author : Shardul Sisodiya

Description : Write a simple program to send some data from parent to the child process.

Date: 12th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pipefds[2];

    if (pipe(pipefds)) {
        perror("Could not open pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child_id = fork();

    if (child_id == -1) {
        perror("Could not create child process");
        exit(EXIT_FAILURE);
    } else if (child_id == 0) {
        close(pipefds[1]);
        char childBuff[100] = {0};

        if (read(pipefds[0], childBuff, sizeof(childBuff) - 1) < 0) {
            perror("Child process: Could not read from the pipe");
            exit(EXIT_FAILURE);
        }

        printf("Child process: Message from pipe - %s\n", childBuff);
    } else {
        close(pipefds[0]);
        char parentMessage[] = "Hello from Parent to Child";

        printf("Parent process: Sending message to Child\n");

        if (write(pipefds[1], parentMessage, sizeof(parentMessage)) < 0) {
            perror("Parent process: Could not write to the pipe");
            exit(EXIT_FAILURE);
        }
    }

    wait(0);
    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Parent process: Sending message to Child
Child process: Message from pipe - Hello from Parent to Child
============================================================================
*/
