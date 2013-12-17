cmake_minimum_required(VERSION 2.6)
project(Pathfinding)
set(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

find_package(SFML 2.1 REQUIRED graphics system window audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIRS})
	set(LIBS ${LIBS} ${SFML_LIBRARIES})
endif(SFML_FOUND)

set(SOURCE
	src/square.cpp
	src/board.cpp
)

include_directories(
	./include
)

set(EXECUTABLE_OUTPUT_PATH ./bin)
add_executable(pathfinding src/main.cpp ${SOURCE})
target_link_libraries(pathfinding ${LIBS})
