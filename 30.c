/*
============================================================================
Name : 30.c

Author : Shardul Sisodiya

Description :
Write a program to create a shared memory.
    a. write some data to the shared memory
    b. attach with O_RDONLY and check whether you are able to overwrite.
    c. detach the shared memory
    d. remove the shared memory

Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void) {
    int shmid;
    key_t key = ftok(".", 'a');

    if (key == -1) {
        perror("Could not create unique key");
        exit(EXIT_FAILURE);
    }

    shmid = shmget(key, 1024, IPC_CREAT | 0744);

    if (shmid == -1) {
        perror("Could not create shared memory");
        exit(EXIT_FAILURE);
    }

    void *data = shmat(shmid, (void*) 0, 0);

    if (!data) {
        perror("Could not attach the memory");
        exit(EXIT_FAILURE);
    }

    printf("Enter the data to be written to the shared memory:\n");
    scanf("%[^\n]", (char*)data);

    printf("Data written to shared memory:\n%s\n", (char*)data);

    if (shmdt(data) == -1) {
        perror("Could not detach the shared memory");
        exit(EXIT_FAILURE);
    }

    printf("Successfully detached the shared memory\n");

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Could not remove the shared memory");
        exit(EXIT_FAILURE);
    }

    printf("Successfully removed the shared memory\n");

    exit(EXIT_SUCCESS);
}

/*
============================================================================
OUTPUT:
Enter the data to be written to the shared memory:
Hello World
Data written to shared memory:
Hello World
Successfully detached the shared memory
Successfully removed the shared memory
============================================================================
*/
