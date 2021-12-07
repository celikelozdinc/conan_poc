cmake_minimum_required(VERSION 3.20.0)


#========== Global Configurations =============#
#project(Calculator CXX)
project(Calculator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
#add_compile_options(-std=c++17)  


set(CMAKE_VERBOSE_MAKEFILE ON)

message("[INFO] =>> CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message("[INFO] =>> CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

message(" [INFO] =>> CONAN_LIBS = ${CONAN_LIBS} " )

add_executable(Calculator calculator.cpp)
target_link_libraries(Calculator PRIVATE ${CONAN_LIBS})

add_executable(CalculatorTest calculator_test.cpp)
target_link_libraries(CalculatorTest PRIVATE ${CONAN_LIBS})



