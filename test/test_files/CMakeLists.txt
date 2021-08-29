project(test_files)

file(GLOB test_files_paths
        "*.csv")

file(WRITE include/TestFilePaths.h
        "#pragma once\n"
        )

foreach(test_file ${test_files_paths})
    get_filename_component(FILE_VAR ${test_file} NAME_WE)
    string(TOUPPER ${FILE_VAR} FILE_VAR)
    set(LINE "constexpr const char* ${FILE_VAR} = \"${test_file}\"\;\n")
    file(APPEND include/TestFilePaths.h ${LINE})
endforeach()

add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

target_include_directories(${PROJECT_NAME} INTERFACE include)

message("-- Added: ${PROJECT_NAME}")