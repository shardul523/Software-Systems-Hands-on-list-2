/*
============================================================================
Name : 4.c

Author : Shardul Sisodiya

Description :
Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define CLOCK_FREQ 4.7 * 1e9

unsigned long long time_stamp() {
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc": "=A" (dst));
    return dst;
}

int main(void) {
    unsigned long long start = time_stamp();

    for (int i = 0; i < 100; i++) getppid();

    unsigned long long end = time_stamp();

    printf("Time taken for 100 getppid calls = %lf sec\n", (end - start) / (CLOCK_FREQ));
}

/*
============================================================================
OUTPUT:
Time taken for 100 getppid calls = 0.000030 sec
============================================================================
*/
