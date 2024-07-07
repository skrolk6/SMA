cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME "SMA")
project(${PROJECT_NAME}
        DESCRIPTION "Simple moving average"
        )

add_executable(${PROJECT_NAME} main.cpp)