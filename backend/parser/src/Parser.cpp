#include "Parser.h"

#include "rapidcsv.h"

#include "Utils.h"

namespace
{
    constexpr const int NO_COLUMN = 0;
    constexpr const int KEY_COLUMN = 1;
    constexpr const int VALUE_COLUMN = 2;
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
        auto key = Utils::trim(row[KEY_COLUMN]);

        /// STEP II - prepare values
        auto valuesStr = row[VALUE_COLUMN];
        // remove whitespaces
        valuesStr.erase(std::remove_if(valuesStr.begin(),
                                       valuesStr.end(),
                                       [](unsigned char x) { return std::isspace(x); }),
                        valuesStr.end());
        // split string
        auto values = Utils::split(std::move(valuesStr), ",");
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

