project(logger)

add_library(${PROJECT_NAME}
        src/Logger.cpp
        include/Logger.h
        include/ConsoleLogger.h)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

message("-- Added: ${PROJECT_NAME}")