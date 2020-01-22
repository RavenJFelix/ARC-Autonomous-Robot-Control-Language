cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

add_subdirectory(main)
add_subdirectory(core)
set(dir_src)

list(TRANSFORM dir_src PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)

set(sources
	${sources}
	dir_src
	PARENT_SCOPE)
