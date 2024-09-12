/*
============================================================================
Name : 9.c

Author : Shardul Sisodiya

Description :
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

Date: 11th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigintHandler(int sig) {
    printf("\nCatching SIGINT and overriding default behaviour\n");
}

int main(void) {
    if (signal(SIGINT, sigintHandler) == SIG_ERR) {
        perror("Could not change the SIGINT handler");
        return 1;
    }

    printf("SIGINT Handler modified. Press (Ctrl + C) to test...\n");

    pause();

    printf("Program finished executing successfully\n");

    return 0;
}

/*
============================================================================
OUTPUT:
SIGINT Handler modified. Press (Ctrl + C) to test...
^C
Catching SIGINT and overriding default behaviour
Program finished executing successfully
============================================================================
*/
