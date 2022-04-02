project(app-imgui)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE IMGUI gui-imgui controller)

message("-- Added: ${PROJECT_NAME}")