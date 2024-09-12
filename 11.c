/*
============================================================================
Name : 11.c

Author : Shardul Sisodiya

Description :
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

Date: 11th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigintHandler(int sig) {
    printf("\nIgnoring SIGINT\n");
}

int main(void) {
    struct sigaction sga;

    sga.sa_handler = sigintHandler;

    sigemptyset(&sga.sa_mask);

    sga.sa_flags = 0;

    if (sigaction(SIGINT, &sga, NULL) == -1) {
        perror("Could not ignore SIGINT\n");
        return 1;
    }

    printf("SIGINT is now being ignored\n");

    sleep(10);

    printf("Resetting SIGINT to default behaviour...\n");

    sga.sa_handler = SIG_DFL;

    if (sigaction(SIGINT, &sga, NULL) == -1) {
        perror("Could not reset SIGINT to default behaviour");
        return 1;
    }

    printf("Reset Successful\n");
    printf("The program will safely exit within the next 10 sec\n");

    sleep(10);

    printf("The program finished it's execution\n");
}

/*
============================================================================
OUTPUT:
SIGINT is now being ignored
^C
Ignoring SIGINT
Resetting SIGINT to default behaviour...
Reset Successful
The program will safely exit within the next 10 sec
^C
============================================================================
*/
