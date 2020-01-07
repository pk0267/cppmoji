cmake_minimum_required(VERSION 3.15)
project(cpp_emoji)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_MACOSX_RPATH 1)
endif()
set(GCC_COVERAGE_COMPILE_FLAGS "--std=c++1z")

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(cpr)
include_directories(${CPR_INCLUDE_DIRS})
add_executable(cpp_emoji main.cpp cppmoji.h cppmoji.cpp HTTPRequest.hpp)

target_link_libraries(cpp_emoji ${CPR_LIBRARIES})


