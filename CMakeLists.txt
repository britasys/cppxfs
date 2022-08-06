cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

option(APP_BUILD_SAMPLES "build samples" OFF)
option(APP_BUILD_TESTS "build tests" OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#project name
set(PROJECT_NAME cppconnect)

# app directories
set(APP_TESTS_DIR ./tests)
set(APP_SAMPLES_DIR ./samples)
set(APP_MODULES_DIR ./modules)
set(APP_INCLUDE_DIR ./inc)
set(APP_SOURCE_DIR ./src)

# build modules
add_subdirectory(${APP_MODULES_DIR})

#project name
set(PROJECT_NAME cppdevice)

file(GLOB_RECURSE APP_SOURCE_FILES ${APP_SOURCE_DIR}/*.cpp)

set(APP_INCLUDE_DIRS ${APP_INCLUDE_DIR}
                     ${APP_SOURCE_DIR}/common/
                     ${APP_SOURCE_DIR}/xfs/
                     ${APP_SOURCE_DIR}/xfs/common/xfs/
                     ${APP_SOURCE_DIR}/xfs/common/xfs_w/
                     ${APP_SOURCE_DIR}/xfs/xfsapi_w/)

# project
#project(${PROJECT_NAME} VERSION 1.0)
#add_compile_options(
#    $<$<CONFIG:>:/MT>
#    $<$<CONFIG:Debug>:/MTd>
#    $<$<CONFIG:Release>:/MT>
#)
#add_library(${PROJECT_NAME} SHARED ${APP_SOURCE_FILES})
#target_compile_definitions(${PROJECT_NAME} PRIVATE CPPCONNECT_EXPORTS)
#target_include_directories(${PROJECT_NAME} PRIVATE ${APP_INCLUDE_DIR}
#                                           PRIVATE ${APP_SOURCE_DIR}
#                                           PRIVATE ${APP_SOURCE_DIR}/Include/common/
#                                           PRIVATE ${APP_SOURCE_DIR}/Include/XFS/
#                                           PRIVATE ${APP_SOURCE_DIR}/Include/XFS_W/
#                                           PRIVATE ${APP_SOURCE_DIR}/Include/NXFS/
#                                           PRIVATE ${APP_MODULES_DIR}/cppmsgwnd/inc/)
#
# samples
if(APP_BUILD_SAMPLES)
    set(SAMPLE_PROJECTS cppconnect_sample_1)
    foreach(SAMPLE_PROJECT ${SAMPLE_PROJECTS})
        project(${SAMPLE_PROJECT} VERSION 1.0)
        add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
        )
        add_executable(${SAMPLE_PROJECT} ${APP_SAMPLES_DIR}/${SAMPLE_PROJECT}.cpp)
        target_include_directories(${SAMPLE_PROJECT} PRIVATE ${APP_INCLUDE_DIR})
        target_link_directories(${SAMPLE_PROJECT} PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
        add_dependencies(${SAMPLE_PROJECT} ${PROJECT_NAME})
    endforeach()
endif(APP_BUILD_SAMPLES)

# tests
if(APP_BUILD_TESTS)
    set(TEST_PROJECTS gtests)
    foreach(TEST_PROJECT ${TEST_PROJECTS})
        project(${TEST_PROJECT} VERSION 1.0)
        add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
        )
        add_executable(${TEST_PROJECT} ${APP_TESTS_DIR}/${TEST_PROJECT}.cpp)
        target_link_directories(${TEST_PROJECT} PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
        target_include_directories(${PROJECT_NAME} PRIVATE ${APP_INCLUDE_DIRS}
                                                   PRIVATE ${APP_MODULES_DIR}/googletest/googletest/include/)
    endforeach()
endif(APP_BUILD_TESTS)