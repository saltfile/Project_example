cmake_minimum_required(VERSION 3.17)
project(ServerLab)

set(CMAKE_CXX_STANDARD 11)

add_executable(ServerLab main.cpp self_main.h ser_lab/ser_one.cpp lab_byte/fun_bytes.cpp lab_crc/crc_lab.cpp)