#pragma once

#include <algorithm>

namespace Utils
{
    inline std::string trim(const std::string& string)
    {
        auto start = string.begin();
        while (start != string.end() && std::isspace(*start)) {
            start++;
        }

        auto end = string.end();
        do {
            end--;
        } while (std::distance(start, end) > 0 && std::isspace(*end));

        return std::string(start, end + 1);
    }

    inline std::vector <std::string> split(std::string _str, const std::string& _deli)
    {
        std::vector <std::string> words;
        size_t pos;
        std::string word;
        while ((pos = _str.find(_deli)) != std::string::npos) {
            std::string token = _str.substr(0, pos);
            token = trim(token);
            words.emplace_back(token);
            _str.erase(0, pos + _deli.length());
        }
        _str = trim(_str);
        words.emplace_back(_str);

        return std::move(words);
    }

    inline std::string removeWhitespaces(std::string _str)
    {
        _str.erase(std::remove_if(_str.begin(), _str.end(), [](unsigned char x) { return std::isspace(x); }),
                   _str.end());
        return _str;
    }

    inline bool ends_with(const std::string& value, const std::string& ending)
    {
        if(ending.size() > value.size()) return false;
        return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
    }
}
