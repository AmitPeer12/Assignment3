cmake_minimum_required(VERSION 3.17)
project(Assignment3)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(Assignment3
        include/connectionHandler.h
        include/outputReader.h
        include/inputReader.h
        src/inputReader.cpp
        src/BGRSclient.cpp
        src/outputReader.cpp
        src/echoClient.cpp
        src/connectionHandler.cpp)