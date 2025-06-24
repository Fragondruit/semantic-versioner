#!/bin/bash

# Format all C++ files in the project
echo "Formatting C++ files with clang-format..."

# Format header and source files
clang-format -i semantic_version.h semantic_version.cpp semver.m.cpp

echo "Formatting complete!" 