/*
============================================================================
Name : 8g.c

Author : Shardul Sisodiya

Description :
Write a separate program using signal system call to catch the following signals.
    g. SIGPROF (use setitimer system call)

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include <string.h>

void sigprofHandler(int sig) {
    printf("Caught SIGPROF signal\n");
    exit(EXIT_SUCCESS);
}

int main(void) {
    printf("Setting SIGPROF signal to go off in 4 sec\n");

    signal(SIGPROF, sigprofHandler);

    struct itimerval timer;

    memset(&timer, 0, sizeof(timer));

    timer.it_value.tv_sec = 4;

    if (setitimer(ITIMER_PROF, &timer, NULL) != 0) {
        perror("Could not set up the timer");
        exit(EXIT_FAILURE);
    }

    for (;;);
}

/*
============================================================================
OUTPUT:
Setting SIGPROF signal to go off in 4 sec
Caught SIGPROF signal
============================================================================
*/
