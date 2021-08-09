#pragma once

#include <string>
#include <memory>

#include "FileBase.h"

class ParserBase
{
public:
    ParserBase() = default;
    ParserBase(const std::string& _filePath) { filePath = _filePath; }
    void setFile(const std::string& _filePath) { filePath = _filePath; }

    virtual void parse() = 0;
    FileBase& getParsed() { return *file; }

protected:
    std::string filePath{};
    std::unique_ptr<FileBase> file;
};