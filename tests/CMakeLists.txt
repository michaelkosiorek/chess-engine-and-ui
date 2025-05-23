add_executable(
    test_math_utils
    test_math_utils.cpp
)

add_executable(
    test_masking_helpers
    test_masking_helpers.cpp
)

target_include_directories(test_math_utils PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(test_masking_helpers PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    test_math_utils PRIVATE
    GTest::gtest_main
    math_lib
)

target_link_libraries(
    test_masking_helpers PRIVATE
    GTest::gtest_main
    chess_engine_lib
)

include(GoogleTest)
gtest_discover_tests(test_math_utils)
gtest_discover_tests(test_masking_helpers)