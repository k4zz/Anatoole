project(parser)

add_library(${PROJECT_NAME}
        include/ParserBase.h
        include/FileBase.h
        src/ProtocolParser.cpp
        include/ProtocolParser.h)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger controller)

message("-- Added: ${PROJECT_NAME}")