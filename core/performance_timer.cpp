#include "performance_timer.h"

void PerformanceTimer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

double PerformanceTimer::stop() {
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end_time - start_time;
    return elapsed.count();
}

