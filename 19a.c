/*
============================================================================
Name : 19a.c

Author : Shardul Sisodiya

Description :
Create a FIFO file by
    a. mknod command

Date: 13th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        perror("Please pass the name of the fifo file as well");
        exit(EXIT_FAILURE);
    }

    printf("Creating a fifo file named %s\n", argv[1]);

    if (!fork()) {
        execlp("mknod", "mknod", argv[1], "p", (char*) NULL);
        perror("Could not execute the command");
        exit(EXIT_FAILURE);
    }

    wait(NULL);
    printf("Successfully created %s\n", argv[1]);
}

/*
============================================================================
OUTPUT:
Creating a fifo file named myfifo
Successfully created myfifo
============================================================================
*/
