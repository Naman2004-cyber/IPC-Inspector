#include "mq_debugger.h"
#include "logger.h"

#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define QUEUE_NAME "/ipc_inspector_queue"
#define MAX_MSG_SIZE 256

void run_mq_demo() {
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);

    if (mq == -1) {
        log_event("Message Queue creation/open failed");
        return;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // CHILD → RECEIVER
        char buffer[MAX_MSG_SIZE];

        mq_receive(mq, buffer, MAX_MSG_SIZE, nullptr);
        log_event(std::string("MQ: Child received -> ") + buffer);

        mq_close(mq);
        _exit(0);
    } else {
        // PARENT → SENDER
        const char *msg = "Hello from parent via message queue";

        mq_send(mq, msg, strlen(msg) + 1, 1);
        log_event("MQ: Parent sent message");

        wait(nullptr);

        mq_close(mq);
        mq_unlink(QUEUE_NAME);
    }
}
