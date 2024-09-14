/*
============================================================================
Name : 24.c

Author : Shardul Sisodiya

Description :
Write a program to create a message queue and print the key and message queue id.

Date: 14th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

int main(void) {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0766 | IPC_CREAT | IPC_EXCL);

    printf("Key = 0x%0x\t Message ID = %d\n", key, msgid);
}

/*
============================================================================
OUTPUT:
Key = 0x610202a4	 Message ID = 0
============================================================================
*/
