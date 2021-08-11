#pragma once

#include <string>
#include <map>
#include <utility>
#include <iostream>

struct Entry
{
    Entry() = default;

    Entry(std::string _no, std::string _key, std::string _value)
            : no(_no)
            , key(_key)
            , value(_value)
    {}

    std::string no;
    std::string key;
    std::string value;
};

struct ProtocolModel
{
    ProtocolModel() = default;

    std::map<int, Entry> protocolEntries;
};