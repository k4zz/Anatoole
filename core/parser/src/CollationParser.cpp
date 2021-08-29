#include "CollationParser.h"

#include "rapidcsv.h"

#include "Utils.h"

void CollationParser::parse(std::string _path)
{
    clear();

    // open csv
    rapidcsv::Document doc;
    try {
        doc.Load(_path, rapidcsv::LabelParams(-1, -1));
    } catch (const std::exception& e) {
        throw std::runtime_error("Problem with opening/reading collation file: " + _path);
    }

    for (auto rowIdx = 0; rowIdx < doc.GetRowCount(); rowIdx++) {
        std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);

        /// STEP I - prepare key
        std::string key;
        try
        {
            key = Utils::trim(row.at(mKeyColumn));
        } catch (const std::out_of_range& e)
        {
            throw std::runtime_error("Provided key column is greater than available columns");
        }

        /// STEP II - prepare values
        std::string valuesStr;
        try
        {
            valuesStr = row.at(mValueColumn);
        } catch (const std::out_of_range& e)
        {
            throw std::runtime_error("Provided value column is greater than available columns");
        }
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
        if (entries.find(key) not_eq entries.end()) {
            entries[key].insert(entries[key].end(), values.begin(), values.end());
        } else {
            entries[key] = std::move(values);
        }
    }
}
