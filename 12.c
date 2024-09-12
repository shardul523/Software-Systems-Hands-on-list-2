/*
============================================================================
Name : 12.c

Author : Shardul Sisodiya

Description :
Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.

Date: 12th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    pid_t child_id = fork();

    if (child_id == -1) {

        perror("Could not create child process");

        return 1;

    } else if (child_id == 0) {

        printf("Child Process: PID = %d\n", getpid());
        printf("Child Process: Parent PID = %d\n", getppid());
        printf("Sending SIGKILL signal to parent...\n");

        if (kill(getppid(), SIGKILL) == -1) {
            perror("Child process: Could not send SIGKILL signal to parent");
            return 1;
        }

        sleep(1);

        printf("Child Process: New Parent ID = %d\n", getppid());

    } else {

        printf("Parent Process: PID = %d\n", getpid());

        while (1) {
            sleep(1);
        }
    }
}

/*
============================================================================
OUTPUT:
Parent Process: PID = 4715
Child Process: PID = 4716
Child Process: Parent PID = 4715
Sending SIGKILL signal to parent...
Killed
Child Process: New Parent ID = 1
============================================================================
*/
