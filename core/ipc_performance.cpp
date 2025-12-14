#include "ipc_performance.h"
#include "performance_timer.h"
#include "logger.h"

#include "pipe_debugger.h"
#include "mq_debugger.h"
#include "shm_debugger.h"

#include <iostream>

void run_ipc_performance_test() {
    PerformanceTimer timer;
    double time_taken;

    std::cout << "\n--- IPC PERFORMANCE COMPARISON ---\n";

    // PIPE
    timer.start();
    run_pipe_demo();
    time_taken = timer.stop();
    log_event("PERFORMANCE | PIPE: " + std::to_string(time_taken) + " ms");
    std::cout << "PIPE: " << time_taken << " ms\n";

    // MESSAGE QUEUE
    timer.start();
    run_mq_demo();
    time_taken = timer.stop();
    log_event("PERFORMANCE | MESSAGE QUEUE: " + std::to_string(time_taken) + " ms");
    std::cout << "MESSAGE QUEUE: " << time_taken << " ms\n";

    // SHARED MEMORY
    timer.start();
    run_shm_demo();
    time_taken = timer.stop();
    log_event("PERFORMANCE | SHARED MEMORY: " + std::to_string(time_taken) + " ms");
    std::cout << "SHARED MEMORY: " << time_taken << " ms\n";
}
