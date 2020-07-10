cmake_minimum_required(VERSION 3.5)

IF (CMAKE_HOST_WIN32)
        MESSAGE(STATUS "current platform: Windows")
        SET(CMAKE_C_COMPILER "I:/MSYS2/mingw64/bin/gcc.exe")
        SET(CMAKE_CXX_COMPILER "I:/MSYS2/mingw64/bin/g++.exe")
ENDIF()

project(Composite LANGUAGES C CXX)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

aux_source_directory(./src SRCS)
add_executable(Composite ${SRCS})

