/*
============================================================================
Name : 21_second.c

Author : Shardul Sisodiya

Description : Write two programs so that both can communicate by FIFO -Use two way communications.

Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_PATH1 "myfifo1"
#define FIFO_PATH2 "myfifo2"

int main(int argc, char** argv) {
    mkfifo(FIFO_PATH1, 0666);
    mkfifo(FIFO_PATH2, 0666);

    char inBuff[100] = {0};
    char outBuff[] = "Message from second program";
    int fifo1 = open(FIFO_PATH1, O_RDONLY);
    int fifo2 = open(FIFO_PATH2, O_WRONLY);


    printf("Sending message to first process...\n");
    if (write(fifo2, outBuff, strlen(outBuff) + 1) < 0) {
        perror("Could not write to the fifo2");
        exit(EXIT_FAILURE);
    }
    printf("Message sent successfully\n");

    printf("Reading message from first process...\n");
    if (read(fifo1, inBuff, sizeof(inBuff) - 1) < 0) {
        perror("Could not read from the fifo1");
        exit(EXIT_FAILURE);
    }
    printf("Message received: %s\n", inBuff);

    close(fifo1);
    close(fifo2);
}

/*
============================================================================
OUTPUT:
Sending message to first process...
Message sent successfully
Reading message from first process...
Message received: Message from first program
============================================================================
*/
