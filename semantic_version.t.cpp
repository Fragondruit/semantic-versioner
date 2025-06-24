#include "semantic_version.h"
#include <gtest/gtest.h>

TEST(SemanticVersionTest, ParsingWorks) {
    auto v = SemanticVersion::parse("1.2.3");
    EXPECT_EQ(v.getMajor(), 1);
    EXPECT_EQ(v.getMinor(), 2);
    EXPECT_EQ(v.getPatch(), 3);
    EXPECT_EQ(v.getPrerelease(), "");
    EXPECT_EQ(v.getBuild(), "");

    auto v2 = SemanticVersion::parse("2.0.1-alpha+build.5");
    EXPECT_EQ(v2.getMajor(), 2);
    EXPECT_EQ(v2.getMinor(), 0);
    EXPECT_EQ(v2.getPatch(), 1);
    EXPECT_EQ(v2.getPrerelease(), "alpha");
    EXPECT_EQ(v2.getBuild(), "build.5");
}

TEST(SemanticVersionTest, ComparisonWorks) {
    auto v1 = SemanticVersion::parse("1.2.3");
    auto v2 = SemanticVersion::parse("1.2.4");
    auto v3 = SemanticVersion::parse("2.0.0-alpha");
    EXPECT_LT(v1, v2);
    EXPECT_GT(v2, v1);
    EXPECT_NE(v1, v3);
    EXPECT_EQ(v1, SemanticVersion::parse("1.2.3"));
}

TEST(SemanticVersionTest, BumpingWorks) {
    auto v = SemanticVersion::parse("1.2.3");
    v.bumpPatch();
    EXPECT_EQ(v.toString(), "1.2.4");
    v.bumpMinor();
    EXPECT_EQ(v.toString(), "1.3.0");
    v.bumpMajor();
    EXPECT_EQ(v.toString(), "2.0.0");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
