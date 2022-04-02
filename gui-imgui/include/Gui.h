#include <string>

#include "LoggerWindow.h"

class Gui
{
public:
    Gui() {init();}

    void init();
    void show();
    void onAnalyze();

private:
    std::string protocolPath{};
    std::string collationPath{};
    std::string protocolNameLetter{};
    std::string protocolNumberLetter{};
    std::string collationNameLetter{};
    std::string collationNumberLetter{};

    LoggerWindow logConsoleWindow{};
};