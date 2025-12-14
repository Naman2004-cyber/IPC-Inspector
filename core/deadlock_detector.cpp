#include "deadlock_detector.h"
#include "logger.h"
#include <map>
#include <string>

using namespace std;

static map<string, string> held;
static map<string, string> waiting;

void acquire_resource(const char* process, const char* resource) {
    held[process] = resource;
    log_event(string(process) + " acquired " + resource);
}

void wait_for_resource(const char* process, const char* resource) {
    waiting[process] = resource;
    log_event(string(process) + " waiting for " + resource);
}

void simulate_deadlock() {
    log_event("P1 acquired SEM_A");
    log_event("P1 waiting for SEM_B");

    log_event("P2 acquired SEM_B");
    log_event("P2 waiting for SEM_A");

    log_event("DEADLOCK DETECTED between P1 and P2");
}

