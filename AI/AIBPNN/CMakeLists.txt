cmake_minimum_required (VERSION 3.5)

set(PROJ AIBPNN)
set(SRCS AnnClassifier.h  DataNode.h  Neuron.h AnnClassifier.cpp  Client.cpp  DataNode.cpp  Neuron.cpp)

project(${PROJ})

add_executable(${PROJ} ${SRCS})

#target_link_libraries(${PROJ} -lgmp)
