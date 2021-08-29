#include <gtest/gtest.h>
#include "ProtocolParser.h"
#include "TestFilePaths.h"

TEST(ProtocolParser, Parser_ValidFile_ReadsSeverEntries)
{
    auto path = FULLY_CORRECT_PROTOCOL;

    auto protocolParser = ProtocolParser();
    protocolParser.parse(path);
    auto entries = protocolParser.getEntries();

    ASSERT_EQ(entries.size(), 4);
}

TEST(ProtocolParser, Parser_InvalidFile_ThrowsException)
{
    auto path = "xxx";

    auto protocolParser = ProtocolParser();
    EXPECT_THROW(protocolParser.parse(path), std::runtime_error);
}

TEST(ProtocolParser, Parser_MissingLine_ThrowsException)
{
    auto path = MISSING_LINE_PROTOCOL;

    auto protocolParser = ProtocolParser();
    EXPECT_THROW(protocolParser.parse(path), std::runtime_error);
}