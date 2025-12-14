#ifndef PERFORMANCE_TIMER_H
#define PERFORMANCE_TIMER_H

#include <chrono>

class PerformanceTimer {
private:
    std::chrono::high_resolution_clock::time_point start_time;

public:
    void start();
    double stop(); // returns time in milliseconds
};

#endif
