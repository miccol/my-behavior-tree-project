project(mybehaviortreeproject)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

#link_directories(/usr/local/lib)

find_package(BTpp REQUIRED)
message("the value of BTPP_INCLUDE_DIRS: " ${BTPP_INCLUDE_DIRS})
message("the value of BTPP_LIBRARIES: " ${BTPP_LIBRARIES})

include_directories(/usr/local/include/btpp)

message("dir included ")

add_executable(${PROJECT_NAME} ${SRC_LIST})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${BTPP_LIBRARIES})

