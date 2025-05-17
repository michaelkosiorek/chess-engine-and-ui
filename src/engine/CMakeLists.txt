add_library(chess_app
    chess_engine.cpp
    chess_interface.cpp
    engine_helpers.cpp
)

# include path
target_include_directories(chess_app PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
