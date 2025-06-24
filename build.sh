#!/bin/bash
set -e

# Remove previous build directory if it exists
if [ -d build ]; then
    echo "Removing old build directory..."
    rm -rf build
fi

# Create build directory
mkdir build
cd build

# Configure project
cmake ..

# Build all targets
cmake --build .

echo "Build complete!" 