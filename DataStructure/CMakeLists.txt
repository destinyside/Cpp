cmake_minimum_required(VERSION 3.5)

IF (CMAKE_HOST_WIN32)
        MESSAGE(STATUS "current platform: Windows")
        SET(CMAKE_C_COMPILER "I:/MSYS2/mingw64/bin/gcc.exe")
        SET(CMAKE_CXX_COMPILER "I:/MSYS2/mingw64/bin/g++.exe")
ENDIF()

project(DataStructure LANGUAGES C CXX)

add_subdirectory(AVLTree)
add_subdirectory(BinaryTree)
add_subdirectory(RedBlackTree)
