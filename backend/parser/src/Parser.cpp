#include "Parser.h"

#include "rapidcsv.h"

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
    try
    {
        doc.Load(path, rapidcsv::LabelParams(-1, -1));
    } catch (const std::exception& e) {
        LOG_ERROR("Problem with opening/reading file: " + path);
        LOG_DEBUG(e.what());
    }

    for(auto rowIdx = 0; rowIdx < doc.GetRowCount(); rowIdx++)
    {
        std::vector<std::string> row = doc.GetRow<std::string>(rowIdx);
        protocolModel.protocolEntries[rowIdx] = Entry(row[NO_COLUMN], row[KEY_COLUMN], row[VALUE_COLUMN]);
        //LOG_DEBUG(row[NO_COLUMN] + " " + row[KEY_COLUMN] + " " + row[VALUE_COLUMN]);
    }
}

