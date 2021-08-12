cmake_minimum_required(VERSION 3.20)

project(Anatoole
        VERSION 0.1
        LANGUAGES CXX)

configure_file(
        ${PROJECT_SOURCE_DIR}/cmake/version.h.in
        ${PROJECT_SOURCE_DIR}/app/include/version.h)

add_subdirectory(3rdparty/rapidcsv)
add_subdirectory(backend)
add_subdirectory(app)
add_subdirectory(gui)