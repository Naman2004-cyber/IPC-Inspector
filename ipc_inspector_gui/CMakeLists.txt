cmake_minimum_required(VERSION 3.5)

project(ipc_inspector_gui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/ipc
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/include
)

# 🔑 VERY IMPORTANT (this fixes ui_mainwindow.h)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
# Tell Qt where backend headers are
include_directories(
    ../include
    ../ipc
    ../core
)

add_executable(ipc_inspector_gui
    main.cpp
    mainwindow.cpp

    ../ipc/pipe_debugger.cpp
    ../ipc/mq_debugger.cpp
    ../ipc/shm_debugger.cpp

    ../core/logger.cpp
    ../core/deadlock_detector.cpp
deadlock_detector
.h
)

target_link_libraries(ipc_inspector_gui
    Qt5::Widgets
    rt
    pthread
)
