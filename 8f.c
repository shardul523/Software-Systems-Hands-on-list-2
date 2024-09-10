/*
============================================================================
Name : 8f.c

Author : Shardul Sisodiya

Description :
Write a separate program using signal system call to catch the following signals.
    f. SIGVTALRM (use setitimer system call)

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void sigvtalrmHandler(int sig) {
    printf("Caught SIGVTALRM Signal after 4 sec of CPU-time\n");
    exit(EXIT_SUCCESS);
}

int main(void) {
    signal(SIGVTALRM, sigvtalrmHandler);

    printf("Setting SIGVTALRM signal to go off after consuming 4 sec of CPU-time\n");

    struct itimerval timer;

    memset(&timer, 0, sizeof(timer));

    timer.it_value.tv_sec = 4;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) != 0) {
        perror("Could not set timer");
        exit(EXIT_FAILURE);
    }

    for (;;);
}

/*
============================================================================
OUTPUT:
Setting SIGVTALRM signal to go off after consuming 4 sec of CPU-time
Caught SIGVTALRM Signal after 4 sec of CPU-time
============================================================================
*/
