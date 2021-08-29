#include <gtest/gtest.h>
#include "CollationParser.h"
#include "TestFilePaths.h"

TEST(CollationParser, Parser_ValidFile_ReadsSeverEntries)
{
    auto path = FULLY_CORRECT_COLLATION;

    auto collationParser = CollationParser();
    collationParser.parse(path);
    auto entries = collationParser.getEntries();

    ASSERT_EQ(entries.size(), 7);
}

TEST(CollationParser, Parser_InvalidFile_ThrowsException)
{
    auto path = "xxx";

    auto collationParser = CollationParser();
    EXPECT_THROW(collationParser.parse(path), std::runtime_error);
}

TEST(CollationParser, Parser_MissingLine_ThrowsException)
{
    auto path = MISSING_LINE_COLLATION;

    auto collationParser = CollationParser();
    EXPECT_THROW(collationParser.parse(path), std::runtime_error);
}