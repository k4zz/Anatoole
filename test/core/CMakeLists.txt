add_executable(test_parser TestParser.cpp)
target_link_libraries(test_parser gtest gmock gtest_main parser)
add_test(NAME test_parser COMMAND test_parser)