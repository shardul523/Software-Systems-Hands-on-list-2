/*
============================================================================
Name : 5.c

Author : Shardul Sisodiya

Description :
Write a program to print the system limitation of
    a. maximum length of the arguments to the exec family of functions.
    b. maximum number of simultaneous process per user id.
    c. number of clock ticks (jiffy) per second.
    d. maximum number of open files
    e. size of a page
    f. total number of pages in the physical memory
    g. number of currently available pages in the physical memory.

Date: 10th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/resource.h>

void printLimit(char* lim_name, int lim_val) {
    errno = 0;
    long limit = sysconf(lim_val);
    if (limit < 0) {
        if (errno != 0)
            printf("There was an error in getting %s limit: %s\n", lim_name, strerror(errno));
        else
            printf("%s: Not supported\n", lim_name);
    } else {
        printf("%s: %ld\n", lim_name, limit);
    }
}

int main(void) {
    struct rlimit lim;

    printLimit("Maximum length of the arguments to the exec family of functions : ", _SC_ARG_MAX);
    printf("Maximum number of simultaneous process per user id\n");
    if (getrlimit(RLIMIT_NPROC, &lim) == 0) {
        if (lim.rlim_cur == RLIM_INFINITY)
            printf("Soft Limit = unlimited");
        else
            printf("Soft Limit = %lu\n", lim.rlim_cur);

        if (lim.rlim_max == RLIM_INFINITY)
            printf("Hard Limit = unlimited\n");
        else
            printf("Hard Limit = %lu\n", lim.rlim_max);
    }
    printLimit("Number of clock ticks (jiffy) per second : ", _SC_CLK_TCK);
    printLimit("Maximum number of open files : ", _SC_OPEN_MAX);
    printLimit("Size of a page : ", _SC_PAGESIZE);
    printLimit("Total number of pages in the physical memory : ", _SC_PHYS_PAGES);
    printLimit("Number of currently available pages in the physical memory : ", _SC_AVPHYS_PAGES);
}

/*
============================================================================
OUTPUT:
Maximum length of the arguments to the exec family of functions : : 2097152
Maximum number of simultaneous process per user id : : 46309
Number of clock ticks (jiffy) per second : : 100
Maximum number of open files : : 1048576
Size of a page : : 4096
Total number of pages in the physical memory : : 2988040
Number of currently available pages in the physical memory : : 1633891
============================================================================
*/
