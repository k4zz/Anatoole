#include <string>
#include "Gui.h"
#include "imgui.h"
#include "imgui_stdlib.h"

namespace
{
    int filterOnlyLetters(ImGuiInputTextCallbackData* data)
    {
        ImWchar c = data->EventChar;
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            return 1;
        data->EventChar += 'A'-'a';
        return 0;
    }
}

void Gui::show()
{
    logConsoleWindow.show();

    ImGui::Begin("Anatoole");

    ImGui::BeginGroup();
    {
        ImGui::Text("Protocol");
        ImGui::InputText("Path##protocolPath", &protocolPath);
        ImGui::PushItemWidth(100);
        ImGui::InputText("Name##protocolName", &protocolNameLetter, ImGuiInputTextFlags_CallbackCharFilter, filterOnlyLetters);
        ImGui::InputText("Number##protocolNumber", &protocolNumberLetter, ImGuiInputTextFlags_CallbackCharFilter, filterOnlyLetters);
        ImGui::PopItemWidth();
    }
    ImGui::EndGroup();

    ImGui::Dummy(ImVec2(0, 10));

    ImGui::BeginGroup();
    {
        ImGui::Text("Collation");
        ImGui::InputText("Path##collationPath", &collationPath);
        ImGui::PushItemWidth(100);
        ImGui::InputText("Name##collationName", &collationNameLetter, ImGuiInputTextFlags_CallbackCharFilter, filterOnlyLetters);
        ImGui::InputText("Number##collationNumber", &collationNumberLetter, ImGuiInputTextFlags_CallbackCharFilter, filterOnlyLetters);
        ImGui::PopItemWidth();
    }
    ImGui::EndGroup();

    ImGui::Dummy(ImVec2(0, 10));

    if(ImGui::Button("Analyze"))
    {
        onAnalyze();
    }

    ImGui::End();

}

void Gui::init()
{
}

void Gui::onAnalyze()
{
    LOG_ERROR("NOICE");
}


