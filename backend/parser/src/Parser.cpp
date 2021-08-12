#include "Parser.h"

#include "rapidcsv.h"

namespace
{
    constexpr const int NO_COLUMN = 0;
    constexpr const int KEY_COLUMN = 1;
    constexpr const int VALUE_COLUMN = 2;

    std::vector<std::string> split(std::string _str, const std::string& _deli)
    {
        std::vector<std::string> words;
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

Parser::Parser(std::string _path)
        : path(_path)
        , withHeader(false)
{
    // open csv
    rapidcsv::Document doc;
    try {
        doc.Load(path, rapidcsv::LabelParams(-1, -1));
    } catch (const std::exception& e) {
        LOG_ERROR("Problem with opening/reading file: " + path);
        LOG_DEBUG(e.what());
    }

    for (auto rowIdx = 0; rowIdx < doc.GetRowCount(); rowIdx++) {
        std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);

        /// STEP I - prepare key
        auto key = trim(row[KEY_COLUMN]);

        /// STEP II - prepare values
        auto valuesStr = row[VALUE_COLUMN];
        // remove whitespaces
        valuesStr.erase(std::remove_if(valuesStr.begin(),
                                       valuesStr.end(),
                                       [](unsigned char x) { return std::isspace(x); }),
                        valuesStr.end());
        // split string
        auto values = split(std::move(valuesStr), ",");
        // remove empty strings
        values.erase(std::remove(values.begin(), values.end(), ""),
                     values.end());

        /// STEP III - add to map
        if (protocolEntries.find(key) not_eq protocolEntries.end()) {
            protocolEntries[key].insert(protocolEntries[key].end(), values.begin(), values.end());
        } else {
            protocolEntries[key] = std::move(values);
        }
    }
}

