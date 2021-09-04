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

// Wrong stuff

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
    ASSERT_TRUE(analyzer.getProblems().at(0).type == ProblemType::RedundantPosition);
}

TEST(Analyzer, Analyzer_NonExistingPositionInProtocol_ProblemTypeNonExistingPosition)
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
    ASSERT_TRUE(analyzer.getProblems().at(0).type == ProblemType::NonExistingPosition);
}

//TODO: actually problem type should be NonExistingName or sth but not worth to implement right now
TEST(Analyzer, Analyzer_NonExistingNameInProtocol_ProblemTypeRedundantPosition)
{
    Entries entriesProtocol = {
            {"1", {"A", "B"}},
            {"2", {"B", "C"}}
    };

    Entries entriesCollation = {
            {"A", {"1"}},
            {"B", {"1", "2"}},
            {"C", {"2"}},
            {"D", {"1"}}
    };

    Analyzer analyzer = Analyzer(entriesProtocol, entriesCollation);
    ASSERT_EQ(analyzer.problemsCount(), 1);
    ASSERT_TRUE(analyzer.getProblems().at(0).type == ProblemType::RedundantPosition);
}

//Missing stuff

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