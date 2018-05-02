cmake_minimum_required(VERSION 3.8.0)
project(leetcode)

add_compile_options(-std=c++11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(. SOURCE_FILES)
    
foreach(ITEM ${SOURCE_FILES})
    get_filename_component(FILE ${ITEM} NAME)
    get_filename_component(TARGET ${ITEM} NAME_WE)
    add_executable(${TARGET} ${FILE})
endforeach()