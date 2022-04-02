cmake_minimum_required(VERSION 3.20)

project(Anatoole
        VERSION 0.1
        LANGUAGES CXX)

option(TEST_ENABLE "" ON)
option(QTGUI "" OFF)

configure_file(
        ${PROJECT_SOURCE_DIR}/cmake/version.h.in
        ${PROJECT_SOURCE_DIR}/app/include/version.h)

add_subdirectory(3rdparty/rapidcsv)
add_subdirectory(3rdparty/googletest)
add_subdirectory(utils)
add_subdirectory(core)
if(${QTGUI})
    add_subdirectory(app)
    add_subdirectory(gui)
else()
    add_subdirectory(3rdparty/imgui 3rdparty/imgui/build)
    add_subdirectory(app-imgui)
    add_subdirectory(gui-imgui)
endif()

if(${TEST_ENABLE})
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()