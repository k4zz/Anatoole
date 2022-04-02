#include "LoggerWindow.h"

void LoggerWindow::init()
{
    Logger::instance().subscribe(this);
}

void LoggerWindow::show()
{
    ImGui::Begin("Log console");
    static ImGuiTableFlags flags = ImGuiTableFlags_SizingFixedFit;
    if (ImGui::BeginTable("Log", 4, flags))
    {
        for (auto const& logMsg : logPool)
        {
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            ImGui::Text(logMsg.fileName.c_str());
            ImGui::TableSetColumnIndex(1);
            ImGui::Text(logMsg.level.c_str());
            ImGui::TableSetColumnIndex(2);
            ImGui::Text(logMsg.msg.c_str());
            ImGui::TableSetColumnIndex(3);
            ImGui::Text(logMsg.line.c_str());
        }
        ImGui::EndTable();
    }

    ImGui::End();

}

void LoggerWindow::log(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line)
{
    logPool.push_back({_msg, toString(_level), _fileName, std::to_string(_line)});
}
