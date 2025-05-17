add_executable(
    test_engine_helpers test_engine_helpers.cpp
)

target_link_libraries(
    test_engine_helpers chess_app
    GTest::gtest_main
)

# include path
target_include_directories(chess_app PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)


include(GoogleTest)
gtest_discover_tests(test_engine_helpers)
