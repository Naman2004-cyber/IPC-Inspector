#ifndef DEADLOCK_DETECTOR_H
#define DEADLOCK_DETECTOR_H

#include <string>

// Register resource acquisition
void acquire_resource(const std::string &process,
                      const std::string &resource);

// Register resource waiting
void wait_for_resource(const std::string &process,
                       const std::string &resource);

// Check for circular wait
void detect_deadlock();
void simulate_deadlock();
#endif
