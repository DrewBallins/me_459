cmake_minimum_required (VERSION 2.8)
project(HW09)

# Generate two executables associated with the ME459 HW09
add_executable(task1 generator.c driver1.c collide.c)
add_executable(task2 math_utils.c driver2.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm")