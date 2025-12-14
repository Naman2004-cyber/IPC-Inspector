#ifndef DEADLOCK_DETECTOR_H
#define DEADLOCK_DETECTOR_H

#include <string>

void acquire_resource(const std::string &process,
                      const std::string &resource);

void wait_for_resource(const std::string &process,
                       const std::string &resource);

void detect_deadlock();
void simulate_deadlock();
#endif
