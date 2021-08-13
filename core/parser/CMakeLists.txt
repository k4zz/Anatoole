project(parser)

add_library(${PROJECT_NAME} STATIC
        include/ParserBase.h
        include/CSVParser.h
        include/CollationParser.h
        src/CollationParser.cpp
        include/ProtocolParser.h
        src/ProtocolParser.cpp
        )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger rapidcsv utils)

message("-- Added: ${PROJECT_NAME}")