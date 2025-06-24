#ifndef SEMANTIC_VERSION_H
#define SEMANTIC_VERSION_H

#include <string>

class SemanticVersion {
private:
    int major;
    int minor;
    int patch;
    std::string prerelease;
    std::string build;

public:
    SemanticVersion(int major = 0, int minor = 0, int patch = 0, const std::string& prerelease = "",
                    const std::string& build = "");

    // Parse version string (e.g., "1.2.3-alpha+build")
    static SemanticVersion parse(const std::string& version);

    // Convert to string
    std::string toString() const;

    // Getters
    int getMajor() const {
        return major;
    }
    int getMinor() const {
        return minor;
    }
    int getPatch() const {
        return patch;
    }
    std::string getPrerelease() const {
        return prerelease;
    }
    std::string getBuild() const {
        return build;
    }

    // Comparison operators
    bool operator==(const SemanticVersion& other) const;
    bool operator<(const SemanticVersion& other) const;
    bool operator>(const SemanticVersion& other) const;
    bool operator<=(const SemanticVersion& other) const;
    bool operator>=(const SemanticVersion& other) const;
    bool operator!=(const SemanticVersion& other) const;

    // Bump methods
    void bumpMajor();
    void bumpMinor();
    void bumpPatch();
};

#endif // SEMANTIC_VERSION_H