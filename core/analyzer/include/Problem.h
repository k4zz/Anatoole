#pragma once

enum class ProblemType
{
    MissingPosition = 0,
    MissingName,
    RedundantPosition,
    RedundantName,
    NonExistingPosition,
};

struct Problem
{
    ProblemType type{};
    std::string protocolPosition{};
    std::string name{};
    int protocolRow{};
    int collationRow{};
};