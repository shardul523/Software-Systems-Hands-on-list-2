/*
============================================================================
Name : 8b.c

Author : Shardul Sisodiya

Description :
Write a separate program using signal system call to catch the following signals.
    b. SIGINT

Date: 10th Sep, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sigintHandler(int sig) {
    printf("\nCaught Signal Interrupt. Exiting gracefully...\n");
}

int main(void) {
    printf("Process running indefinitely...\t Press (Ctrl + C) to exit\n");
    signal(SIGINT, sigintHandler);
    pause();
}

/*
============================================================================
OUTPUT:
Process running indefinitely...	 Press (Ctrl + C) to exit
^C
Caught Signal Interrupt. Exiting gracefully...
============================================================================
*/
