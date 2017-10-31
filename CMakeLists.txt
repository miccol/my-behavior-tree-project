project(mybehaviortreeproject)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(BTpp REQUIRED)

message("the value of BTpp_INCLUDE_DIRS: " ${BTpp_INCLUDE_DIRS})
message("the value of BTpp_LIBRARIES: " ${BTpp_LIBRARIES})

include_directories(${BTpp_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} ${SRC_LIST})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${BTpp_LIBRARIES})

