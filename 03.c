/*
============================================================================
Name : 3.c

Author : Shardul Sisodiya

Description : Write a program to set (any one) system resource limit. Use setrlimit system call.

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/resource.h>

void printLimit(struct rlimit *rlim) {
    printf("Soft Limit = ");
    if (rlim->rlim_cur == RLIM_INFINITY)
        printf("unlimited");
    else
        printf("%lu", rlim->rlim_cur);
    printf("\n");

    printf("Hard Limit = ");
    if (rlim->rlim_max == RLIM_INFINITY)
        printf("unlimited");
    else
        printf("%lu", rlim->rlim_max);
    printf("\n");
}

int main(void) {
    struct rlimit lim;

    if (getrlimit(RLIMIT_NOFILE, &lim) != 0) {
        perror("Could not access the resource limit");
        exit(EXIT_FAILURE);
    }

    printf("Number of Open Files (Old Limits)\n");

    printLimit(&lim);

    lim.rlim_cur = 4;
    lim.rlim_max = 5;

    if (setrlimit(RLIMIT_NOFILE, &lim) != 0) {
        perror("Could not set the resource limit");
        exit(EXIT_FAILURE);
    }

    printf("Number of Open Files (New Limits)\n");

    printLimit(&lim);
}

/*
============================================================================
OUTPUT:
Number of Open Files (Old Limits)
Soft Limit = 1048576
Hard Limit = 1048576
Number of Open Files (New Limits)
Soft Limit = 4
Hard Limit = 5
============================================================================
*/
