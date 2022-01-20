cmake_minimum_required(VERSION 3.21)
project(info_defense_caesar)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(info_defense_caesar main.cpp Caesar.cpp Decryptor.cpp)
