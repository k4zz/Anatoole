#include "CollationParser.h"

#include "rapidcsv.h"

#include "Utils.h"

bool CollationParser::parse(std::string _path)
{
    clear();

    // open csv
    rapidcsv::Document doc;
    try {
        doc.Load(_path, rapidcsv::LabelParams(-1, -1));
    } catch (const std::exception& e) {
        LOG_ERROR("Problem with opening/reading collation file: " + _path);
        return false;
    }

    for (auto rowIdx = 0; rowIdx < doc.GetRowCount(); rowIdx++) {
        std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);

        /// STEP I - prepare key
        auto key = Utils::trim(row[mKeyColumn]);

        /// STEP II - prepare values
        auto valuesStr = row[mValueColumn];
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

    return true;
}
