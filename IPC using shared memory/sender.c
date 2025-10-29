#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    void *shared_memory;
    char buffer[100];
    int shmid;

    // Create shared memory
    shmid = shmget((key_t)1232, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    printf("Shared memory ID: %d\n", shmid);

    // Attach
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    printf("Process attached at %p\n", shared_memory);

    printf("Enter data to write: ");
    read(0, buffer, sizeof(buffer));
    strcpy(shared_memory, buffer);

    printf("Data written: %s\n", (char*)shared_memory);
    return 0;
}
