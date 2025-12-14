#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

#include <sys/types.h>

// Creates a child process and runs the given function in it
pid_t create_process(void (*child_function)());

#endif
