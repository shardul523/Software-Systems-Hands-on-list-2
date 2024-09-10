/*
============================================================================
Name : 2.c

Author : Shardul Sisodiya

Description : Write a program to print the system resource limits. Use getrlimit system call.

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void printLimit(char* name, int res) {
    struct rlimit limit;

    if (getrlimit(res, &limit) != 0) {
        perror("Could not get resource limits");
        exit(EXIT_FAILURE);
    }

    printf("%s :\n", name);

    if (limit.rlim_cur == RLIM_INFINITY)
        printf("Soft Limit = unlimited\n");
    else
        printf("Soft Limit = %lu\n", limit.rlim_cur);

    if (limit.rlim_max == RLIM_INFINITY)
        printf("Hard Limit = unlimited\n");
    else
        printf("Hard Limit = %lu\n", limit.rlim_max);

    printf("\n");
}

int main(void) {
    printLimit("CPU Time", RLIMIT_CPU);
    printLimit("File Size", RLIMIT_FSIZE);
    printLimit("Data Segment Size", RLIMIT_DATA);
    printLimit("Stack Size", RLIMIT_STACK);
    printLimit("Core File Size", RLIMIT_CORE);
    printLimit("Resident set size", RLIMIT_RSS);
    printLimit("Number of Processes", RLIMIT_NPROC);
    printLimit("Number of Open Files", RLIMIT_NOFILE);
    printLimit("Address Space", RLIMIT_AS);
}

/*
============================================================================
OUTPUT:
CPU Time :
Soft Limit = unlimited
Hard Limit = unlimited

File Size :
Soft Limit = unlimited
Hard Limit = unlimited

Data Segment Size :
Soft Limit = unlimited
Hard Limit = unlimited

Stack Size :
Soft Limit = 8388608
Hard Limit = unlimited

Core File Size :
Soft Limit = 0
Hard Limit = unlimited

Resident set size :
Soft Limit = unlimited
Hard Limit = unlimited

Number of Processes :
Soft Limit = 46309
Hard Limit = 46309

Number of Open Files :
Soft Limit = 1048576
Hard Limit = 1048576

Address Space :
Soft Limit = unlimited
Hard Limit = unlimited

============================================================================
*/
