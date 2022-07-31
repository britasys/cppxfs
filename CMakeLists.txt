cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(APP_BUILD_SAMPLES "build samples" OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#project name
set(PROJECT_NAME cppconnect)

# app directories
set(APP_BOOST_DIR $ENV{BOOST_ROOT})
set(APP_SAMPLES_DIR ./samples)
set(APP_MODULES_DIR ./modules)
set(APP_INCLUDE_DIR ./inc)
set(APP_SOURCE_DIR ./src)

#project name
set(PROJECT_NAME cppxfs)

file(GLOB_RECURCE APP_SOURCE_FILES ${APP_SOURCE_DIR}/*.cpp)

# project
project(${PROJECT_NAME} VERSION 1.0)
add_library(${PROJECT_NAME} SHARED APP_SOURCE_FILES)
target_compile_definitions(${PROJECT_NAME} PRIVATE CPPCONNECT_EXPORTS)
target_include_directories(${PROJECT_NAME} PRIVATE ${APP_INCLUDE_DIR}
                                           PRIVATE ${APP_SOURCE_DIR}
                                           PRIVATE ${APP_MODULES_DIR}/cppmsgwnd/inc/)

# samples
if(APP_BUILD_SAMPLES)
    set(SAMPLE_PROJECTS cppconnect_sample_1)
    foreach(SAMPLE_PROJECT ${SAMPLE_PROJECTS})
            project(${SAMPLE_PROJECT} VERSION 1.0)
            add_executable(${SAMPLE_PROJECT} ${APP_SAMPLES_DIR}/${SAMPLE_PROJECT}.cpp)
            target_include_directories(${SAMPLE_PROJECT} PRIVATE ${APP_INCLUDE_DIR})
            target_link_directories(${SAMPLE_PROJECT} PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
            add_dependencies(${SAMPLE_PROJECT} ${PROJECT_NAME})
    endforeach()
endif(APP_BUILD_SAMPLES)