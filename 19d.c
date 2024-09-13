/*
============================================================================
Name : 19d.c

Author : Shardul Sisodiya

Description :
Create a FIFO file by
    d. mkfifo library function

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

    if (mkfifo(argv[1], 0666) == -1) {
        perror("Could not create FIFO");
        exit(EXIT_FAILURE);
    }

    printf("Successfully created a FIFO named %s using mkfifo library function\n", argv[1]);
}

/*
============================================================================
OUTPUT:
Successfully created a FIFO named myfifo using mkfifo library function
============================================================================
*/
