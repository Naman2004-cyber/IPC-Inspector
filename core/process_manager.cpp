#include "process_manager.h"
#include "logger.h"

#include <unistd.h>   // fork(), getpid()
#include <sys/wait.h> // wait()

pid_t create_process(void (*child_function)()) {
    pid_t pid = fork();

    if (pid < 0) {
        log_event("Process creation failed");
        return -1;
    }

    if (pid == 0) {
        // CHILD PROCESS
        log_event("Child process started. PID = " + std::to_string(getpid()));
        child_function();
        _exit(0);
    } else {
        // PARENT PROCESS
        log_event("Parent process PID = " + std::to_string(getpid()) +
                  " created child PID = " + std::to_string(pid));
        wait(nullptr);
    }

    return pid;
}
