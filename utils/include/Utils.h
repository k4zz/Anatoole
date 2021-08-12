#pragma once

namespace Utils
{
    std::vector <std::string> split(std::string _str, const std::string& _deli)
    {
        std::vector <std::string> words;
        size_t pos = 0;
        std::string word;
        while ((pos = _str.find(_deli)) != std::string::npos) {
            std::string token = _str.substr(0, pos);
            //remove whitespaces
            token.erase(std::remove_if(token.begin(), token.end(), [](unsigned char x) { return std::isspace(x); }),
                        token.end());
            words.emplace_back(token);
            _str.erase(0, pos + _deli.length());
        }
        _str.erase(std::remove_if(_str.begin(), _str.end(), [](unsigned char x) { return std::isspace(x); }),
                   _str.end());
        words.emplace_back(_str);

        return std::move(words);
    }

    std::string trim(const std::string& string)
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
}
