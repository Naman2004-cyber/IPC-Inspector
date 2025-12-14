#include <iostream>

#include "logger.h"
#include "pipe_debugger.h"
#include "mq_debugger.h"
#include "shm_debugger.h"
#include "deadlock_detector.h"
#include "ipc_performance.h"

using namespace std;

int main() {
    int choice;

    log_event("IPC-Inspector started (CLI mode)");

    while (true) {
        cout << "\n===== IPC-INSPECTOR =====\n";
        cout << "1. Run Pipe IPC Demo\n";
        cout << "2. Run Message Queue IPC Demo\n";
        cout << "3. Run Shared Memory + Semaphore Demo\n";
        cout << "4. Run Deadlock Simulation\n";
	cout << "5. Run ALL Modules\n";
	cout << "6. Run IPC Performance Comparison\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Running Pipe IPC...\n";
                log_event("User selected Pipe IPC");
                run_pipe_demo();
                break;

            case 2:
                cout << "Running Message Queue IPC...\n";
                log_event("User selected Message Queue IPC");
                run_mq_demo();
                break;

            case 3:
                cout << "Running Shared Memory IPC...\n";
                log_event("User selected Shared Memory IPC");
                run_shm_demo();
                break;

            case 4:
                cout << "Running Deadlock Simulation...\n";
                log_event("User selected Deadlock Simulation");
                simulate_deadlock();
                break;
		
	    case 5:
                cout << "Running ALL modules...\n";
                log_event("User selected ALL modules");
                run_pipe_demo();
                run_mq_demo();
                run_shm_demo();
                simulate_deadlock();
                break;

	    case 6:
             cout << "Running IPC Performance Comparison...\n";
             log_event("User selected IPC Performance Comparison");
             run_ipc_performance_test();
             break;


            case 0:
                log_event("IPC-Inspector exiting");
                cout << "Exiting IPC-Inspector...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}

           

    







