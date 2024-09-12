/*
============================================================================
Name : 16.c

Author : Shardul Sisodiya

Description :
Write a program to send and receive data from parent to child vice versa. Use two way
communication.

Date: 12th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    // Parent writes to pipe 1 and reads from pipe 2
    // Child writes to pipe 2 and reads from pipe 1
    int pipefds1[2], pipefds2[2];
    pid_t child_id;

    if (pipe(pipefds1) || pipe(pipefds2)) {
        perror("Could not open pipe(s)");
        exit(EXIT_FAILURE);
    }

    child_id = fork();

    if (child_id == -1) {
        perror("Could not create child process");
        exit(EXIT_FAILURE);
    } else if (child_id == 0) {
        close(pipefds2[0]);
        close(pipefds1[1]);
        char child_inp[] = "Hello from child to parent";
        char child_out[100] = {0};

        if (write(pipefds2[1], child_inp, sizeof(child_inp) - 1) < 0) {
            perror("Child process: Could not write to the pipe");
            exit(EXIT_FAILURE);
        }

        if (read(pipefds1[0], child_out, sizeof(child_out) - 1) < 0) {
            perror("Child process: Could not read from the pipe");
            exit(EXIT_FAILURE);
        }

        printf("Child process: Message from parent -\nChild process: %s\n", child_out);
    } else {
        close(pipefds1[0]);
        close(pipefds2[1]);
        char parent_inp[] = "Hello from parent to child";
        char parent_out[100] = {0};

        if (write(pipefds1[1], parent_inp, sizeof(parent_inp) - 1) < 0) {
            perror("Parent process: Could not write to the pipe");
            exit(EXIT_FAILURE);
        }

        if (read(pipefds2[0], parent_out, sizeof(parent_out) - 1) < 0) {
            perror("Parent process: Could not read from the pipe");
            exit(EXIT_FAILURE);
        }

        printf("Parent process: Message from child -\nParent process: %s\n", parent_out);
    }


    wait(0);
    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Parent process: Message from child -
Parent process: Hello from child to parent
Child process: Message from parent -
Child process: Hello from parent to child
============================================================================
*/
