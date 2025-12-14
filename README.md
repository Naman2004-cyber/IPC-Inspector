IPC-Inspector 🛠️

An Inter-Process Communication (IPC) Debugger & Analyzer

📌 Project Overview

IPC-Inspector is a command-line based debugging and analysis tool developed using C/C++ on Ubuntu Linux.
The project demonstrates and analyzes multiple Inter-Process Communication (IPC) mechanisms used in operating systems, including:

Pipes

Message Queues

Shared Memory with Semaphores

Deadlock Simulation and Detection

IPC Performance Comparison

The tool is designed to help students and developers understand, debug, and compare IPC mechanisms, making it ideal for Operating Systems coursework.

🎯 Objectives

To demonstrate working of different IPC mechanisms in Linux

To log IPC events for debugging and analysis

To simulate and detect deadlocks

To compare performance of IPC techniques

To provide a modular and extensible IPC debugging framework

⚙️ Features

✅ Pipe-based IPC demonstration

✅ Message Queue IPC demonstration (POSIX MQ)

✅ Shared Memory + Semaphore synchronization

✅ Deadlock simulation and detection

✅ CLI-based interactive menu

✅ Centralized logging system (logs/ipc.log)

✅ IPC performance comparison (time-based)

✅ Modular code structure

✅ GitHub version control with branches and commits

🧩 Project Structure
IPC-Inspector/
│
├── core/
│   ├── logger.cpp
│   ├── deadlock_detector.cpp
│   ├── ipc_performance.cpp
│   └── performance_timer.cpp
│
├── include/
│   ├── logger.h
│   ├── pipe_debugger.h
│   ├── mq_debugger.h
│   ├── shm_debugger.h
│   ├── deadlock_detector.h
│   ├── ipc_performance.h
│   └── performance_timer.h
│
├── ipc/
│   ├── pipe_debugger.cpp
│   ├── mq_debugger.cpp
│   └── shm_debugger.cpp
│
├── logs/
│   └── ipc.log
│
├── main.cpp
├── README.md
└── ipc_inspector   (compiled binary)

🖥️ How to Build & Run (Ubuntu)
1️⃣ Compile
g++ main.cpp \
core/logger.cpp \
ipc/pipe_debugger.cpp \
ipc/mq_debugger.cpp \
ipc/shm_debugger.cpp \
core/deadlock_detector.cpp \
core/ipc_performance.cpp \
core/performance_timer.cpp \
-Iinclude \
-lrt \
-pthread \
-o ipc_inspector

2️⃣ Run
./ipc_inspector

📋 CLI Menu Options
===== IPC-INSPECTOR =====
1. Run Pipe IPC Demo
2. Run Message Queue IPC Demo
3. Run Shared Memory + Semaphore Demo
4. Run Deadlock Simulation
5. Run ALL Modules
6. Run IPC Performance Comparison
0. Exit

🧪 Logging

All IPC events, synchronization steps, deadlock detection, and performance results are logged to:

logs/ipc.log


This log file acts as a debug trace for IPC operations.

📊 IPC Performance Comparison

The tool measures and compares execution time of:

Pipe IPC

Message Queue IPC

Shared Memory IPC

Results are displayed on the terminal and logged for analysis.

🧠 Deadlock Simulation

Simulates circular wait using multiple resources

Detects deadlock conditions

Logs detected deadlocks clearly

🛠️ Technologies Used

Programming Language: C / C++

Operating System: Ubuntu Linux

IPC Mechanisms: Pipes, Message Queues, Shared Memory, Semaphores

Build Tools: g++

Version Control: Git & GitHub

📦 GitHub Workflow

Feature-based branches (feature-*)

Multiple commits with clear messages

Merged into main branch after testing

Revision history maintained as per assignment requirements

🚀 Future Enhancements

GUI-based visualization (Qt)

Real-time log monitoring

Advanced deadlock prevention strategies

IPC throughput and memory usage graphs
