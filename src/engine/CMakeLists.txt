add_library(chess_engine_lib
    board.cpp
    chess_interface.cpp
    masking_helpers.cpp
    move_generation.cpp
    ../math/math_utils.cpp)

# include path
target_include_directories(chess_engine_lib PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
