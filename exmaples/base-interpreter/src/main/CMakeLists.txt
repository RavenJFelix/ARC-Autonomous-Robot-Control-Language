cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(dir_src
	main.cpp)

list(TRANSFORM dir_src PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)

set(sources
	${sources}
	${dir_src}
	PARENT_SCOPE)

