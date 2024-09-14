/*
============================================================================
Name : 8c.c

Author : Shardul Sisodiya

Description :
Write a separate program using signal system call to catch the following signals.
    c. SIGFPE

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>

void sigfpeHandler(int sig) {
    printf("Caught Floating Point Error\n");
    exit(EXIT_FAILURE);
}

int main(void) {
    signal(SIGFPE, sigfpeHandler);
    printf("Trying division by 0\n");
    int x = 10, y = 0;
    int z = x / y;
}

/*
============================================================================
OUTPUT:
Trying division by 0
Caught Floating Point Error
============================================================================
*/
