cmake_minimum_required(VERSION 3.5)

IF (CMAKE_HOST_WIN32)
        MESSAGE(STATUS "current platform: Windows")
        SET(CMAKE_C_COMPILER "I:/MSYS2/mingw64/bin/gcc.exe")
        SET(CMAKE_CXX_COMPILER "I:/MSYS2/mingw64/bin/g++.exe")
ENDIF()

project(CppTest LANGUAGES C CXX)

add_subdirectory(AI)
add_subdirectory(Algorithms)
add_subdirectory(Chaos)
add_subdirectory(DataStructure)
add_subdirectory(DesignPattern)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
add_executable(CppTest lib.h main.c lib.txt)

