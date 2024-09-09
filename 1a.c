// /*
// ============================================================================
// Name : 1a.c

// Author : Shardul Sisodiya

// Description :
// Write a separate program (for each time domain) to set a interval timer in 10sec and
// 10micro second
//     a. ITIMER_REAL

// Date: 9th Sep, 2024.
// ============================================================================
// */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void handleSignal() {
    static int count = 0;
    printf("Timer expired %d time(s): ITIMER_REAL\n", ++count);
    if (count == 10) exit(EXIT_SUCCESS);
}

int main(void) {
    struct itimerval timer;

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    signal(SIGALRM, handleSignal);

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) pause();
}

/*
============================================================================
OUTPUT:
Timer expired 1 time(s): ITIMER_REAL
Timer expired 2 time(s): ITIMER_REAL
Timer expired 3 time(s): ITIMER_REAL
Timer expired 4 time(s): ITIMER_REAL
Timer expired 5 time(s): ITIMER_REAL
Timer expired 6 time(s): ITIMER_REAL
Timer expired 7 time(s): ITIMER_REAL
Timer expired 8 time(s): ITIMER_REAL
Timer expired 9 time(s): ITIMER_REAL
Timer expired 10 time(s): ITIMER_REAL
============================================================================
*/
