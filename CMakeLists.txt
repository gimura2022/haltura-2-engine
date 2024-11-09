cmake_minimum_required(VERSION 3.5)
project(haltura2 C)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-std=c99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(SDL3 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories("include")

file(GLOB_RECURSE SOURCES REALATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
add_executable(main ${SOURCES})

target_link_libraries(main ${SDL3_LIBRARIES})

if(UNIX)
	target_link_libraries(main m)
endif()
