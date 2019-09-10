cmake_minimum_required (VERSION 3.0)

project (NetZero5Boro)

set(HEADER_FILES node.h llist.h bintree.h bintoarray.h NetZeroEnergy.h)

add_library(node node.cpp ${HEADER_FILES}) 

add_library(llist llist.cpp ${HEADER_FILES})

add_library(NetZeroEnergy NetZeroEnergy.cpp ${HEADER_FILES})

add_executable(NetZeroMain NetZeroMain.cpp ${HEADER_FILES})

target_link_libraries(NetZeroMain node llist bintree.h bintoarray.h NetZeroEnergy)

target_compile_options(NetZeroMain PRIVATE -std=c++0x -g -Wall)
