project(app)

add_executable(${PROJECT_NAME}
        src/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
        AUTOMOC ON
        AUTORCC ON
        AUTOUIC ON)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets gui logger parser)

message("-- Added: ${PROJECT_NAME}")