cmake_minimum_required(VERSION 3.17)
project(Server)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server main.cpp ser_drive.h ser_io_start/server.cpp crc/crc.cpp pack/req_dispose.cpp test/testlab.cpp)