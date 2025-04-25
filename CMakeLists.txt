cmake_minimum_required(VERSION 3.2)

project(gradient_project CXX)

include_directories(hpp)


set(SRC
    cpp/test_gradient.cpp 
    
)


add_executable(test_gradient ${SRC})
target_compile_options(test_gradient PRIVATE -g -O0)
