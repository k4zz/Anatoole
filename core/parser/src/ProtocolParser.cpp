#include "ProtocolParser.h"

#include "rapidcsv.h"

#include "Utils.h"

void ProtocolParser::parse(std::string _path)
{
    clear();

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
        LOG_ERROR("Problem with opening/reading file: " + _path);
        LOG_DEBUG(e.what());
    }

    for (auto rowIdx = 0; rowIdx < doc.GetRowCount(); rowIdx++) {
        std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);

        /// STEP I - prepare key
        auto key = Utils::trim(row[mKeyColumn]);

        /// STEP II - prepare values
        auto valuesStr = row[mValueColumn];
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

    LOG_DEBUG("Created " + std::to_string(entries.size()) + " from protocol");
}
