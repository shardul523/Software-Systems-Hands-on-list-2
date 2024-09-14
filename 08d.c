/*
============================================================================
Name : 8d.c

Author : Shardul Sisodiya

Description :
Write a separate program using signal system call to catch the following signals.
    d. SIGALRM (use alarm system call)

Date: 10th Sep, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>

void sigalrmHandler(int sig) {
    printf("Caught SIGALRM signal\n");
}

int main(void) {
    printf("Alarm signal will trigger in 4 sec...\n");
    alarm(4);
    signal(SIGALRM, sigalrmHandler);
    pause();
}

/*
============================================================================
OUTPUT:
Alarm signal will trigger in 4 sec...
Caught SIGALRM signal
============================================================================
*/
