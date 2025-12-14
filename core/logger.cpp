#include "logger.h"
#include <fstream>
#include <ctime>
#include <sys/stat.h>
#include <unistd.h>

void log_event(const std::string &message) {
    // Ensure logs directory exists
    mkdir("logs", 0777);

    std::ofstream logfile("logs/ipc.log", std::ios::app);

    if (!logfile.is_open()) {
        return; // fail silently
    }

    time_t now = time(nullptr);
    logfile << "[" << ctime(&now) << "] " << message << std::endl;
    logfile.close();
}



