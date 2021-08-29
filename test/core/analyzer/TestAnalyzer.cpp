#include <gtest/gtest.h>
#include "Analyzer.h"

TEST(Analyzer, Analyzer_AllValid_ZeroProblems)
{
    Entries entriesProtocol = {
            {"1", {"A", "B"}},
            {"2", {"B", "C"}}
    };

    Entries entriesCollation = {
            {"A", {"1"}},
            {"B", {"1", "2"}},
            {"C", {"2"}}
    };

    Analyzer analyzer = Analyzer(entriesProtocol, entriesCollation);
    ASSERT_EQ(analyzer.problemsCount(), 0);
}

TEST(Analyzer, Analyzer_RedundantNumberInCollation_ProblemTypeRedundantName)
{
    Entries entriesProtocol = {
            {"1", {"A"}},
            {"2", {"B", "C"}}
    };

    Entries entriesCollation = {
            {"A", {"1"}},
            {"B", {"1", "2"}},
            {"C", {"2"}}
    };

    Analyzer analyzer = Analyzer(entriesProtocol, entriesCollation);
    ASSERT_EQ(analyzer.problemsCount(), 1);
    ASSERT_TRUE(analyzer.getProblems().at(0).type == ProblemType::RedundantName);
}

TEST(Analyzer, Analyzer_RedundantPositionInCollation_ProblemTypeRedundantPosition)
{
    Entries entriesProtocol = {
            {"1", {"A", "B"}},
            {"2", {"B", "C"}}
    };

    Entries entriesCollation = {
            {"A", {"1"}},
            {"B", {"1", "2"}},
            {"C", {"2", "7"}}
    };

    Analyzer analyzer = Analyzer(entriesProtocol, entriesCollation);
    ASSERT_EQ(analyzer.problemsCount(), 1);
    ASSERT_TRUE(analyzer.getProblems().at(0).type == ProblemType::RedundantPosition);
}

TEST(Analyzer, Analyzer_MissingNameInCollation_ProblemTypeMissingPosition)
{
    Entries entriesProtocol = {
            {"1", {"A", "B"}},
            {"2", {"B", "C"}}
    };

    Entries entriesCollation = {
            {"A", {"1"}},
            {"B", {"1"}},
            {"C", {"2"}}
    };

    Analyzer analyzer = Analyzer(entriesProtocol, entriesCollation);
    ASSERT_EQ(analyzer.problemsCount(), 1);
    ASSERT_TRUE(analyzer.getProblems().at(0).type == ProblemType::MissingPosition);
}

TEST(Analyzer, Analyzer_MissingNameInCollation_ProblemTypeMissingName)
{
    Entries entriesProtocol = {
            {"1", {"A", "B"}},
            {"2", {"B", "C"}}
    };

    Entries entriesCollation = {
            {"A", {"1"}},
            {"B", {"1", "2"}}
    };

    Analyzer analyzer = Analyzer(entriesProtocol, entriesCollation);
    ASSERT_EQ(analyzer.problemsCount(), 1);
    ASSERT_TRUE(analyzer.getProblems().at(0).type == ProblemType::MissingName);
}