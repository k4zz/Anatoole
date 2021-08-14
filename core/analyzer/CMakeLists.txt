project(analyzer)

add_library(${PROJECT_NAME} STATIC
        include/Analyzer.h
        src/Analyzer.cpp
        )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger)

message("-- Added: ${PROJECT_NAME}")