add_library(chess_engine_lib
    chess_engine.cpp
    chess_interface.cpp
    ../math/math_utils.cpp
)

# include path
target_include_directories(chess_engine_lib PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
