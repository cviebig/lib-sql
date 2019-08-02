cmake_minimum_required(VERSION 3.1)
project(lib-sql)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    # find_package( lib-dependency )
endif()

find_package(Catch2 REQUIRED)

# Boost
find_package( Boost 1.61.0 )
include_directories( ${Boost_INCLUDE_DIR} )


# Library
add_library(sql INTERFACE)
target_include_directories(sql INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
# target_link_libraries(sql INTERFACE dependency)
export(TARGETS sql FILE sqlastConfig.cmake)
export(PACKAGE sql)

# set_property(TARGET sql PROPERTY CXX_STANDARD 14)
# set_property(TARGET sql PROPERTY CXX_STANDARD_REQUIRED ON)


# Catch
enable_testing(true)
set(TEST_ENABLED true)


# Tests
add_subdirectory(test)
