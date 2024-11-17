cmake_minimum_required(VERSION 3.20)

project(rays VERSION 0.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 23)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

file(GLOB_RECURSE RAYS_HEADERS "include/*.h")
file(GLOB_RECURSE RAYS_SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${RAYS_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_options(${PROJECT_NAME} PUBLIC 
    -Wall
    -Wwrite-strings
    -Wstrict-prototypes
    -Wsign-compare
    -fno-common
    -Wtype-limits
    -Wformat-nonliteral
    -Wmissing-declarations
    -fsanitize=address
    -fno-omit-frame-pointer
    -pipe
    #-mavx2
    #-O3
)

target_link_libraries(${PROJECT_NAME} PRIVATE -fsanitize=address)

