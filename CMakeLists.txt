cmake_minimum_required(VERSION 3.17)
project(martix_multiplication CXX)


set(CMAKE_PREFIX_PATH "/opt/hpx")

find_package(HPX REQUIRED)

add_executable(app main.cpp)



# specify necessary lib for a target
target_link_libraries(app HPX::hpx HPX::wrap_main HPX::iostreams_component)