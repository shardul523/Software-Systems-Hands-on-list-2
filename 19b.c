/*
============================================================================
Name : 19b.c

Author : Shardul Sisodiya

Description :
Create a FIFO file by
    b. mkfifo command

Date: 13th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    if (argc < 2) {
        printf("Please enter the name of the FIFO file\n");
        return 1;
    }

    int status;
    printf("Creating a new FIFO file named %s\n", argv[1]);

    if (!fork()) {
        execlp("mkfifo", "mkfifo", argv[1], (char*) NULL);
        exit(EXIT_FAILURE);
    }

    wait(&status);

    if (!WIFEXITED(status)) {
        perror("Could not create a new FIFO file");
        exit(EXIT_FAILURE);
    }

    printf("Successfully created the FIFO file %s\n", argv[1]);
    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Creating a new FIFO file named myfifo2
Successfully created the FIFO file myfifo2
============================================================================
*/
