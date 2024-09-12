/*
============================================================================
Name : 17a.c

Author : Shardul Sisodiya

Description :
Write a program to execute ls -l | wc.
    a. use dup

Date: 13th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pipefds[2];
    pid_t child_id;

    if (pipe(pipefds)) {
        perror("Could not open pipe for executing the process");
        exit(EXIT_FAILURE);
    }

    child_id = fork();

    if (child_id == -1) {
        perror("Could not create child process");
        exit(EXIT_FAILURE);
    } else if (child_id == 0) {
        close(0);
        close(pipefds[1]);
        dup(pipefds[0]);

        execlp("wc", "wc", (char*)NULL);
        perror("Could not execute second command");
        exit(EXIT_FAILURE);
    } else {
        close(1);
        close(pipefds[0]);
        dup(pipefds[1]);

        execlp("ls", "ls", "-l", (char*) NULL);
        perror("Could not execute first command");
        exit(EXIT_FAILURE);
    }

    wait(NULL);
    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
     32     281    1675
============================================================================
*/
