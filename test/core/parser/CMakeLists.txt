add_executable(test_collation_parser TestCollationParser.cpp)
target_link_libraries(test_collation_parser gtest gtest_main gmock parser test_files)
add_test(NAME test_collation_parser COMMAND test_collation_parser)

add_executable(test_protocol_parser TestProtocolParser.cpp)
target_link_libraries(test_protocol_parser gtest gtest_main gmock parser test_files)
add_test(NAME test_protocol_parser COMMAND test_protocol_parser)