/*
============================================================================
Name : 20_sender.c

Author : Shardul Sisodiya

Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_PATH "myfifo"

int main(void) {
    int fifo_fd = open(FIFO_PATH, O_WRONLY);
    char buffMessage[100];

    if (fifo_fd < 0) {
        perror("Could not open fifo");
        exit(EXIT_FAILURE);
    }

    printf("Enter the message to be sent: ");
    scanf("%[^\n]", buffMessage);

    if (write(fifo_fd, buffMessage, strlen(buffMessage) + 1) < 0) {
        perror("Could not write to the pipe");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to the receiver\n");

    close(fifo_fd);
}

/*
============================================================================
OUTPUT:
Enter the message to be sent: Hello World
Message sent to the receiver
============================================================================
*/
