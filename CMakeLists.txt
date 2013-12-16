cmake_minimum_required(VERSION 2.6)
project(Pathfinding)
set(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

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
