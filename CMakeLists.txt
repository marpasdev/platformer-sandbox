cmake_minimum_required(VERSION 3.12)

project(PlatformerSandbox C)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address")
set(CMAKE_C_STANDARD 11)

find_package(SDL2 REQUIRED)

add_executable(PlatformerSandbox main.c grid.c mathutils.c player.c camera.c terrain.c)

target_include_directories(PlatformerSandbox PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(PlatformerSandbox SDL2 SDL2_image SDL2_ttf m)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})