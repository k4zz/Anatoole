project(gui)

add_library(${PROJECT_NAME}
        src/MainWindow.cpp
        include/MainWindow.h
        ui/MainWindow.ui
        src/PathsWidget.cpp
        include/PathsWidget.h
        ui/PathsWidget.ui
        src/LogConsoleWidget.cpp
        include/LogConsoleWidget.h
        ui/LogConsoleWidget.ui
        src/SettingsWidget.cpp
        include/SettingsWidget.h
        ui/SettingsWidget.ui
        )

set_target_properties(${PROJECT_NAME} PROPERTIES
        AUTOMOC ON
        AUTORCC ON
        AUTOUIC ON
        AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets logger)

message("-- Added: ${PROJECT_NAME}")