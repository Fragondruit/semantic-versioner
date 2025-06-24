# Semantic Versioner

A C++ library for parsing and comparing semantic versions according to the [Semantic Versioning 2.0.0](https://semver.org/) specification.

## Features

- Parse semantic version strings (e.g., "1.2.3-alpha+build")
- Compare semantic versions using standard comparison operators
- Support for prerelease versions and build metadata
- Full compliance with SemVer 2.0.0 specification

## Building

This project uses CMake for building. Here's how to build it:

```bash
# Create a build directory
mkdir build
cd build

# Configure the project
cmake ..

# Build the project
make

# Run the executable
./bin/semver
```

## Usage

The `SemanticVersion` class provides the following functionality:

```cpp
// Parse a version string
SemanticVersion v1 = SemanticVersion::parse("1.2.3");
SemanticVersion v2 = SemanticVersion::parse("1.2.4-alpha");

// Compare versions
if (v1 < v2) {
    std::cout << "v1 is older than v2" << std::endl;
}

// Convert back to string
std::string version_str = v1.toString(); // "1.2.3"
```

## Requirements

- C++17 compatible compiler
- CMake 3.10 or higher

## License

This project is open source and available under the MIT License. 