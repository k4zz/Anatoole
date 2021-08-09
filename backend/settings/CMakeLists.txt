project(settings)

add_library(${PROJECT_NAME} INTERFACE
        include/Settings.h)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

target_include_directories(${PROJECT_NAME} INTERFACE include)

message("-- Added: ${PROJECT_NAME}")