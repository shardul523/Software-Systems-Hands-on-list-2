/*
============================================================================
Name : 14.c

Author : Shardul Sisodiya

Description :
Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

Date: 12th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int pipefds[2];
    char inpBuff[100], outBuff[100];

    if (pipe(pipefds)) {
        perror("Could not open the pipe");
        exit(EXIT_FAILURE);
    }

    printf("Please enter the message to be passed to the pipe: ");

    fgets(inpBuff, sizeof(inpBuff), stdin);

    printf("Passing the message to the pipe...\n");

    if (write(pipefds[1], inpBuff, strlen(inpBuff)) < 0) {
        perror("Could not write to the pipe");
        exit(EXIT_FAILURE);
    }

    if (read(pipefds[0], outBuff, sizeof(outBuff)) < 0) {
        perror("Could not read from the pipe");
        exit(EXIT_FAILURE);
    }

    printf("Message read from the pipe: %s", outBuff);

    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Please enter the message to be passed to the pipe: Hello World
Passing the message to the pipe...
Message read from the pipe: Hello World
============================================================================
*/
