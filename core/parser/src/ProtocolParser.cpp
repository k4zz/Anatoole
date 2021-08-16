#include "ProtocolParser.h"

#include "rapidcsv.h"

#include "Utils.h"

bool ProtocolParser::parse(std::string _path)
{
    clear();

    LOG_DEBUG("Protocol settings: " + std::to_string(mKeyColumn) + "  " + std::to_string(mValueColumn));

    // open csv
    rapidcsv::Document doc;
    try {
        doc.Load(_path,
                 rapidcsv::LabelParams(-1, -1),
                 rapidcsv::SeparatorParams(
                         ',',
                         false,
                         rapidcsv::sPlatformHasCR,
                         true,
                         true
                 ));
    } catch (const std::exception& e) {
        LOG_ERROR("Problem with opening/reading protocol file: " + _path);
        return false;
    }

    for (auto rowIdx = 0; rowIdx < doc.GetRowCount(); rowIdx++) {
        std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);

        /// STEP I - prepare key
        std::string key;
        try
        {
            key= Utils::trim(row.at(mKeyColumn));
        } catch (const std::exception& e)
        {
            LOG_ERROR(e.what());
            return false;
        }

        /// STEP II - prepare values
        std::string valuesStr;
        try
        {
            valuesStr = row.at(mValueColumn);
        } catch (const std::out_of_range& e)
        {
            LOG_ERROR("Provided key column is greater than available columns");
            return false;
        }
        // split string
        auto values = Utils::split(valuesStr, "\n");
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
