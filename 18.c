/*
============================================================================
Name : 18.c

Author : Shardul Sisodiya

Description :
Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc -l.

Date: 13th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    int pipefds1[2], pipefds2[2];
    pid_t child1, child2, child3;

    if (pipe(pipefds1) || pipe(pipefds2)) {
        perror("Could not open the pipes");
        exit(EXIT_FAILURE);
    }

    child1 = fork();

    if (child1 == 0) {
        dup2(pipefds1[1], 1);
        close(pipefds1[0]);
        close(pipefds2[0]);
        close(pipefds2[1]);

        execlp("ls", "ls", "-l", (char*) NULL);
    }

    child2 = fork();

    if (child2 == 0) {
        dup2(pipefds1[0], 0);
        dup2(pipefds2[1], 1);
        close(pipefds1[1]);
        close(pipefds2[0]);

        execl("grep", "grep", "^d", (char*) NULL);
    }

    child3 = fork();

    if (child3 == 0) {
        dup2(pipefds2[0], 0);
        close(pipefds1[0]);
        close(pipefds1[1]);
        close(pipefds2[1]);

        execlp("wc", "wc", "-l", (char*) NULL);
    }

    sleep(1);
    printf("Finished executing ls -l | grep ^d | wc -l\n");
    printf("Number of directories in pwd: ");
    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Finished executing ls -l | grep ^d | wc -l
Number of directories in pwd: 2
============================================================================
*/
