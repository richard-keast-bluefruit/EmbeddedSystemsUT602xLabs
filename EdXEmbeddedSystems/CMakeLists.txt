# cmake_minimum_required(VERSION <specify CMake version here>)
project(EdXEmbeddedSystems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    EdXEmbeddedSystems/blinky.c
    EdXEmbeddedSystems/gcc_Debug.h
    EdXEmbeddedSystems/gcc_Release.h
    EdXEmbeddedSystems/hw_nvic.h
    EdXEmbeddedSystems/hw_types.h
    EdXEmbeddedSystems/main.cpp
    EdXEmbeddedSystems/startup_ccs.c
    EdXEmbeddedSystems/startup_ewarm.c
    EdXEmbeddedSystems/startup_gcc.c
    EdXEmbeddedSystems/tm4c123gh6pm.h
    Lab4/gcc_Debug.h
    Lab4/gcc_Release.h)

add_executable(EdXEmbeddedSystems ${SOURCE_FILES})