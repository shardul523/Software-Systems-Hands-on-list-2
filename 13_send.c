/*
============================================================================
Name : 13_send.c

Author : Shardul Sisodiya

Description :
Write two programs: the second program will send the signal (using kill system call).

Date: 12th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>

int main(void) {
    printf("Enter the PID to send SIGSTOP signal to: ");

    int pid;
    scanf("%d", &pid);

    if (kill(pid, SIGSTOP) == -1) {
        perror("Could not send the SIGSTOP signal");
        return 1;
    }

    printf("SIGSTOP signal sent successfully\n");
}

/*
============================================================================
OUTPUT:
Enter the PID to send SIGSTOP signal to: 7267
SIGSTOP signal sent successfully
============================================================================
*/
