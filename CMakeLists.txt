cmake_minimum_required(VERSION 3.8)
project(EasyDriveESP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        EasyDriver.cpp
        EasyDriver.h)

add_executable(EasyDriveESP ${SOURCE_FILES})