# Generate three executables associated with the ME459 HW06
add_executable(task1 task1.c output.c)
add_executable(task2 task2.c output.c)
add_executable(task3 task3.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm")