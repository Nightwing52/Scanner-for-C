cmake_minimum_required(VERSION 3.0)
set(CMAKE_GENERATOR "Ninja")
project("Scanner")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCES
	example.c
	scanner.c
	scanner.h
)


add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib)

