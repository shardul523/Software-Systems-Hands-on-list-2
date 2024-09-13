/*
============================================================================
Name : 19c.c

Author : Shardul Sisodiya

Description :
Create a FIFO file by
    c. mknod system call

Date: 13th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please specify the path of the FIFO file to be created\n");
        return 1;
    }

    if (mknod(argv[1], S_IFIFO | 0666, 0) == -1) {
        perror("Could not create FIFO");
        exit(EXIT_FAILURE);
    }

    printf("Successfully created a FIFO named %s using mknod system call\n", argv[1]);
}

/*
============================================================================
OUTPUT:
Successfully created a FIFO named myfifo using mknod system call
============================================================================
*/
