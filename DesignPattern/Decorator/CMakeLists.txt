cmake_minimum_required(VERSION 3.5)

IF (CMAKE_HOST_WIN32)
        MESSAGE(STATUS "current platform: Windows")
        SET(CMAKE_C_COMPILER "I:/MSYS2/mingw64/bin/gcc.exe")
        SET(CMAKE_CXX_COMPILER "I:/MSYS2/mingw64/bin/g++.exe")
ENDIF()

project(Decorator LANGUAGES CXX)
aux_source_directory(./src SRCS)
add_executable(Decorator ${SRCS})

