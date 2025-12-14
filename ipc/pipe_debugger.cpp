#include "pipe_debugger.h"
#include "logger.h"

#include <unistd.h>   // pipe(), fork(), read(), write()
#include <string.h>   // strlen()
#include <sys/wait.h> // wait()

void run_pipe_demo() {
    int fd[2];

    // Create pipe
    if (pipe(fd) == -1) {
        log_event("Pipe creation failed");
        return;
    }

    pid_t pid = fork();

    if (pid < 0) {
        log_event("Fork failed in pipe demo");
        return;
    }

    if (pid == 0) {
        // CHILD → READER
        close(fd[1]); // close write end

        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));

        log_event(std::string("Pipe: Child received -> ") + buffer);

        close(fd[0]);
        _exit(0);
    } else {
        // PARENT → WRITER
        close(fd[0]); // close read end

        const char *msg = "Hello from parent via pipe";
        write(fd[1], msg, strlen(msg) + 1);

        log_event("Pipe: Parent sent message");

        close(fd[1]);
        wait(nullptr);
    }
}
