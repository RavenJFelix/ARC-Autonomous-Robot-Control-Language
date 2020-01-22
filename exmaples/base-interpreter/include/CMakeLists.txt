set(dir_headers
	)

list(TRANSFORM dir_headers PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)

set(headers
	${headers}
	${dir_headers}
	PARENT_SCOPE)
