cmake_minimum_required(VERSION 3.20)


#========== Global Configurations =============#
project(ConanPoc LANGUAGES CXX)
add_compile_options(-std=c++17)
set(CMAKE_VERBOSE_MAKEFILE ON)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(ConanPoc
    main.cpp
)

target_link_libraries(ConanPoc
    PRIVATE ${CONAN_LIBS}
)



