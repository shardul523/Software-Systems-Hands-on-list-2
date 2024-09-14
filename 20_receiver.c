/*
============================================================================
Name : 20_receiver.c

Author : Shardul Sisodiya

Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_PATH "myfifo"

int main(void) {
    int fifo_fd = open(FIFO_PATH, O_RDONLY);
    char buffMessage[100] = {0};

    if (fifo_fd < 0) {
        perror("Could not open fifo");
        exit(EXIT_FAILURE);
    }

    if (read(fifo_fd, buffMessage, sizeof(buffMessage)) < 0) {
        perror("Could not read from the pipe");
        exit(EXIT_FAILURE);
    }

    printf("Message received from the sender: %s\n", buffMessage);

    close(fifo_fd);
}

/*
============================================================================
OUTPUT:
Message received from the sender: Hello World
============================================================================
*/
