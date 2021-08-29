add_executable(test_analyzer TestAnalyzer.cpp)
target_link_libraries(test_analyzer gtest gtest_main gmock analyzer)
add_test(NAME test_analyzer COMMAND test_analyzer)