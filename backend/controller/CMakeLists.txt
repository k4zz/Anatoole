project(controller)

add_library(${PROJECT_NAME}
        src/Controller.cpp
        include/Controller.h
        include/BaseComponent.h
        include/Mediator.h
        include/EventType.h
        )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE logger parser PUBLIC settings)

message("-- Added: ${PROJECT_NAME}")