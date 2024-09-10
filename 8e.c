/*
============================================================================
Name : 8e.c

Author : Shardul Sisodiya

Description :
Write a separate program using signal system call to catch the following signals.
    e. SIGALRM (use setitimer system call)

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

void sigalrmHandler(int sig) {
    printf("Caught SIGALRM signal\n");
}

int main(void) {
    signal(SIGALRM, sigalrmHandler);

    printf("Setting SIGALRM to go off in 4 sec\n");

    struct itimerval timer;

    memset(&timer, 0, sizeof(timer));

    timer.it_value.tv_sec = 4;

    if (setitimer(ITIMER_REAL, &timer, NULL) != 0) {
        perror("Could not set the alarm");
        return 1;
    }

    pause();
}

/*
============================================================================
OUTPUT:
Setting SIGALRM to go off in 4 sec
Caught SIGALRM signal
============================================================================
*/
