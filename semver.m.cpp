#include "semantic_version.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " [--major|--minor|--patch] <version>\n";
        return 1;
    }

    std::string option = argv[1];
    std::string version_str = argv[2];

    try {
        SemanticVersion version = SemanticVersion::parse(version_str);

        if (option == "--major") {
            version.bumpMajor();
        } else if (option == "--minor") {
            version.bumpMinor();
        } else if (option == "--patch") {
            version.bumpPatch();
        } else {
            std::cerr << "Unknown option: " << option << "\n";
            return 1;
        }

        std::cout << version.toString() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
