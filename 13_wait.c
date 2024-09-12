/*
============================================================================
Name : 13_wait.c

Author : Shardul Sisodiya

Description : Write two programs: first program is waiting to catch SIGSTOP signal,
Find out whether the first program is able to catch the signal or not.

Date: 12th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Waiting for SIGSTOP \nProcess PID: %d\n", getpid());
    while(1) {sleep(1);}
}

/*
============================================================================
OUTPUT:
Waiting for SIGSTOP
Process PID: 7267

[1]+  Stopped                 ./13_wait
============================================================================
*/
