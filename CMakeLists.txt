cmake_minimum_required(VERSION 3.10)

# Project name and version
project(semantic-versioner VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable with all source files
add_executable(semver 
    semver.m.cpp
    semantic_version.cpp
)

# Set compiler flags for better warnings
if(MSVC)
    target_compile_options(semver PRIVATE /W4)
else()
    target_compile_options(semver PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Optional: Set output directory
set_target_properties(semver PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Optional: Add installation
install(TARGETS semver
    RUNTIME DESTINATION bin
) 

add_executable(semantic_version_tests
    semantic_version.t.cpp
    semantic_version.cpp
)

target_include_directories(semantic_version_tests 
    PRIVATE /opt/homebrew/include
)
find_package(GTest REQUIRED)
target_link_libraries(semantic_version_tests GTest::gtest_main)
enable_testing()
