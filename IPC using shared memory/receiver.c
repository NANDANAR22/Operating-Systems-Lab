#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    void *shared_memory;
    int shmid;

    shmid = shmget((key_t)1232, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    printf("Process attached at %p\n", shared_memory);
    printf("Data read from shared memory:\n%s\n", (char*)shared_memory);

    // Detach after reading
    shmdt(shared_memory);

    // Optional: remove shared memory segment (cleanup)
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
