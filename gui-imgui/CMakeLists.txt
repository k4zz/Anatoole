project(gui-imgui)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
               PRIVATE
                   src/Gui.cpp
                   src/LoggerWindow.cpp
               PUBLIC
                   include/Gui.h
                   include/LoggerWindow.h
               )

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           include)

target_link_libraries(${PROJECT_NAME} IMGUI logger)