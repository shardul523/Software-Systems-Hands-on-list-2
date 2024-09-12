/*
============================================================================
Name : 10b.c

Author : Shardul Sisodiya

Description :
Write a separate program using sigaction system call to catch the following signals.
    b. SIGINT

Date: 11th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigintHandler(int sig) {
    printf("\nCaught SIGINT and ending the process gracefully\n");
    exit(EXIT_SUCCESS);
}

int main(void) {
    struct sigaction sga;

    sga.sa_handler = sigintHandler;

    sigemptyset(&sga.sa_mask);

    sga.sa_flags = 0;

    if (sigaction(SIGINT, &sga, NULL) == -1) {
        perror("Could not set the SIGINT handler");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT Handler set. Press (CTRL + C) to check...\n");

    while (1) {
        sleep(1);
    }
}

/*
============================================================================
OUTPUT:
SIGINT Handler set. Press (CTRL + C) to check...
^C
Caught SIGINT and ending the process gracefully
============================================================================
*/
