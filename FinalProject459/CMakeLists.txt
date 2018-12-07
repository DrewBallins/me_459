cmake_minimum_required (VERSION 2.8)
project(FinalProject)

# Generate the executable associated with the ME459 Final Project
add_executable(final driver.c collide.c spheres.c mesh.c output.c)

# Set necessary GCC compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")