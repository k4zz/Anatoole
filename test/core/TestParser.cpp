#include <gtest/gtest.h>
#include "CollationParser.h"

TEST(CollationParser, Parser_ValidFile_ReadsSeverEntries)
{
    auto path = "D:/_CODE/Anatoole/test/test_files/fully_correct_collation.csv";

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
