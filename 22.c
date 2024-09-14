/*
============================================================================
Name : 22.c

Author : Shardul Sisodiya

Description :
Write a program to wait for data to be written into FIFO within 10 seconds,
use select system call with FIFO.

Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/select.h>

#define FIFO_PATH "myfifo"
#define BUFFER_SIZE 1024

int main(void) {
    if (mkfifo(FIFO_PATH, 0666) && errno != EEXIST) {
        perror("There was an error with the FIFO file");
        exit(EXIT_FAILURE);
    }

    int fifo = open(FIFO_PATH, O_RDONLY), ready;
    struct timeval timer;
    fd_set fds;
    char buff[BUFFER_SIZE] = {0};

    if (fifo == -1) {
        perror("Could not open FIFO for reading");
        exit(EXIT_FAILURE);
    }

    timer.tv_sec = 10;
    timer.tv_usec = 0;

    FD_ZERO(&fds);
    FD_SET(fifo, &fds);

    ready = select(fifo + 1, &fds, NULL, NULL, &timer);

    if (ready == -1) {
        perror("There was an error while waiting for fds");
        exit(EXIT_FAILURE);
    }

    if (ready == 0) {
        printf("Timeout: No input received in 10 sec\n");
    } else {
        if (FD_ISSET(fifo, &fds)) {
            if (read(fifo, buff, sizeof(buff) - 1) < 0) {
                perror("Could not read from the FIFO");
                exit(EXIT_FAILURE);
            } else {
                printf("Data received from FIFO: %s\n", buff);
            }
        }
    }

    close(fifo);
    return 0;
}

/*
============================================================================
OUTPUT:
Data received from FIFO: This is a message for program 22.c
============================================================================
*/
