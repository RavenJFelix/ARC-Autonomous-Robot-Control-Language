set(dir_headers
	Pair2D.h
	RoboDefs.h
	Robot.h
	Utility.h
	)

list(TRANSFORM dir_headers PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)

set(headers
	${headers}
	${dir_headers}
	PARENT_SCOPE)
