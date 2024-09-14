/*
============================================================================
Name : 23.c

Author : Shardul Sisodiya

Description :
Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).

Date: 14th Sep, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    long max_files, max_pipe_size;

    max_files = sysconf(_SC_OPEN_MAX);
    max_pipe_size = pathconf("myfifo", _PC_PIPE_BUF);

    printf("Maximum number of files that can be opened: %ld\n", max_files);
    printf("Maximum size of the pipe buffer: %ld\n", max_pipe_size);
}

/*
============================================================================
OUTPUT:
Maximum number of files that can be opened: 1048576
Maximum size of the pipe buffer: 4096
============================================================================
*/
