project(parser)

add_library(${PROJECT_NAME}
        src/Parser.cpp
        include/Parser.h
        )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger rapidcsv utils)

message("-- Added: ${PROJECT_NAME}")