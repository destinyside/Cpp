cmake_minimum_required(VERSION 3.5)

IF (CMAKE_HOST_WIN32)
        MESSAGE(STATUS "current platform: Windows")
        SET(CMAKE_C_COMPILER "I:/MSYS2/mingw64/bin/gcc.exe")
        SET(CMAKE_CXX_COMPILER "I:/MSYS2/mingw64/bin/g++.exe")
ENDIF()

project(Bf2c LANGUAGES C)

aux_source_directory(./src SRCS)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example/mdbt.bf DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(Bf2c ${SRCS})


