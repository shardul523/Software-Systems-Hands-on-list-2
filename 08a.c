/*
============================================================================
Name : 8a.c

Author : Shardul Sisodiya

Description :
Write a separate program using signal system call to catch the following signals.
a. SIGSEGV

Date: 10th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>

void segvHandler(int signum) {
    printf("Caught Segmentation Fault\n");
    exit(EXIT_FAILURE);
}

int main(void) {
    signal(SIGSEGV, segvHandler);
    int *ptr = NULL;
    *ptr = 10;
}

/*
============================================================================
OUTPUT:
Caught Segmentation Fault
============================================================================
*/
