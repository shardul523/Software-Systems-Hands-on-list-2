/*
============================================================================
Name : 10a.c

Author : Shardul Sisodiya

Description :
Write a separate program using sigaction system call to catch the following signals.
    a. SIGSEGV

Date: 11th Sep, 2024.
============================================================================
*/


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigsegvHandler(int sig) {
    printf("Catching SIGSEGV and cleaning up...\n");
    exit(EXIT_FAILURE);
}

int main(void) {
    struct sigaction sg;

    sg.sa_handler = sigsegvHandler;

    sigemptyset(&sg.sa_mask);

    sg.sa_flags = 0;

    if (sigaction(SIGSEGV, &sg, NULL) == -1) {
        perror("Could not set the SIGSEV handler");
        exit(EXIT_FAILURE);
    }

    int *ptr = NULL;
    *ptr = 10;
}

/*
============================================================================
OUTPUT:
Catching SIGSEGV and cleaning up...
============================================================================
*/
