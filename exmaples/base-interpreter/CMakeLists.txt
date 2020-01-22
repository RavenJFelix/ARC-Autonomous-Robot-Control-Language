cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(ARC_Interpreter)

set(sources)
set(headers)

add_subdirectory(src)
add_subdirectory(include)

message(STATUS ${soureces}
add_executable(${PROJECT_NAME} ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} PUBLIC include)
