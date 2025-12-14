#include "shm_debugger.h"
#include "logger.h"

#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

#define SHM_SIZE 1024

void run_shm_demo() {
    // 1. Create shared memory
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        log_event("SHM: Failed to create shared memory");
        return;
    }

    // 2. Attach shared memory
    char *shared_data = (char *) shmat(shmid, nullptr, 0);

    // 3. Create semaphore (shared between processes)
    sem_t semaphore;
    sem_init(&semaphore, 1, 1);  // pshared=1, initial value=1

    pid_t pid = fork();

    if (pid == 0) {
        // CHILD PROCESS → WRITER
        log_event("SHM: Child waiting to write");

        sem_wait(&semaphore);   // LOCK
        log_event("SHM: Child acquired semaphore");

        strcpy(shared_data, "Hello from child via shared memory");
        sleep(1); // simulate slow write

        log_event("SHM: Child wrote data");
        sem_post(&semaphore);   // UNLOCK

        shmdt(shared_data);
        _exit(0);
    } else {
        // PARENT PROCESS → READER
        sleep(1); // ensure child writes first

        log_event("SHM: Parent waiting to read");

        sem_wait(&semaphore);   // LOCK
        log_event(std::string("SHM: Parent read -> ") + shared_data);
        sem_post(&semaphore);   // UNLOCK

        wait(nullptr);

        shmdt(shared_data);
        shmctl(shmid, IPC_RMID, nullptr);
        sem_destroy(&semaphore);
    }
}
