cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(ARC_Interpreter)

set(sources)
set(headers)

add_subdirectory(src)
add_subdirectory(include)

message(STATUS ${headers})
add_executable(${PROJECT_NAME} ${headers} ${sources} )

target_include_directories(${PROJECT_NAME} PUBLIC include)
