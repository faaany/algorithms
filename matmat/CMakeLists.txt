cmake_minimum_required(VERSION 3.10)
project(matmat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER icc)
set(CMAKE_CXX_FLAGS "-qopt-report=5 -qopt-report-phase=vec")
set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_CXX_FLAGS "-xhost")

add_executable(matmat main.cpp matmat.cpp)