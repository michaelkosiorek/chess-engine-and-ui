add_library(math_lib
    math_utils.cpp
)

# include path
target_include_directories(math_lib PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)