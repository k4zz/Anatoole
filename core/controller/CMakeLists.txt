project(controller)

add_library(${PROJECT_NAME} STATIC
        include/Controller.h
        src/Controller.cpp
        )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger PUBLIC parser analyzer utils)

message("-- Added: ${PROJECT_NAME}")