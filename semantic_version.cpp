#include "semantic_version.h"
#include <regex>
#include <stdexcept>

SemanticVersion::SemanticVersion(int major, int minor, int patch, const std::string& prerelease,
                                 const std::string& build)
    : major(major), minor(minor), patch(patch), prerelease(prerelease), build(build) {}

SemanticVersion SemanticVersion::parse(const std::string& version) {
    std::regex version_regex(
        R"(^(\d+)\.(\d+)\.(\d+)(?:-([0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?(?:\+([0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?$)");
    std::smatch match;

    if (!std::regex_match(version, match, version_regex)) {
        throw std::invalid_argument("Invalid semantic version format: " + version);
    }

    int major = std::stoi(match[1]);
    int minor = std::stoi(match[2]);
    int patch = std::stoi(match[3]);
    std::string prerelease = match[4].matched ? match[4].str() : "";
    std::string build = match[5].matched ? match[5].str() : "";

    return SemanticVersion(major, minor, patch, prerelease, build);
}

std::string SemanticVersion::toString() const {
    std::string result =
        std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
    if (!prerelease.empty()) {
        result += "-" + prerelease;
    }
    if (!build.empty()) {
        result += "+" + build;
    }
    return result;
}

bool SemanticVersion::operator==(const SemanticVersion& other) const {
    return major == other.major && minor == other.minor && patch == other.patch &&
           prerelease == other.prerelease;
}

bool SemanticVersion::operator<(const SemanticVersion& other) const {
    if (major != other.major)
        return major < other.major;
    if (minor != other.minor)
        return minor < other.minor;
    if (patch != other.patch)
        return patch < other.patch;

    // Handle prerelease comparison
    if (prerelease.empty() && !other.prerelease.empty())
        return false;
    if (!prerelease.empty() && other.prerelease.empty())
        return true;
    return prerelease < other.prerelease;
}

bool SemanticVersion::operator>(const SemanticVersion& other) const {
    return other < *this;
}

bool SemanticVersion::operator<=(const SemanticVersion& other) const {
    return *this < other || *this == other;
}

bool SemanticVersion::operator>=(const SemanticVersion& other) const {
    return *this > other || *this == other;
}

bool SemanticVersion::operator!=(const SemanticVersion& other) const {
    return !(*this == other);
}

void SemanticVersion::bumpMajor() {
    major++;
    minor = 0;
    patch = 0;
    prerelease.clear();
    build.clear();
}

void SemanticVersion::bumpMinor() {
    minor++;
    patch = 0;
    prerelease.clear();
    build.clear();
}

void SemanticVersion::bumpPatch() {
    patch++;
    prerelease.clear();
    build.clear();
}