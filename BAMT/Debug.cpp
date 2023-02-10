#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"

// Text Colour
int WHITE = 15;
int YELLOW = 14;
int RED = 12;

namespace Debug 
{
    #pragma region LogFunctions
    bool showLogs = true;
    void Debug::Log(std::string output)
    {
        if (!showLogs) return;

        Debug::SetColour(WHITE);
        std::cout << "[" << GetTime() << "]" << " LOG - " << output << std::endl;
    }

    void ShowLogs(bool show)
    {
        std::string showString = show ? "Enabled" : "Disabled";
        std::cout << "[Logs " << showString << "]" << std::endl;
        showLogs = show;
    }
    #pragma endregion LogFunctions

    #pragma region WarningFunctions
    bool showWarnings = true;
    void Debug::LogWarn(std::string output)
    {
        if (!showWarnings) return;

        Debug::SetColour(YELLOW);
        std::cout << "[" << GetTime() << "]" << " WARNING - " << output << std::endl;

        // Set it to white again to prevent things that should be white from not being so.
        Debug::SetColour(WHITE);
    }
    void Debug::ShowWarnings(bool show)
    {
        std::string showString = show ? "Enabled" : "Disabled";
        std::cout << "[Warnings " << showString << "]" << std::endl;
        showWarnings = show;
    }
    #pragma endregion WarningFunctions

    #pragma region ErrorFunctions
    bool showErrors = true;
    void Debug::LogError(std::string output)
    {
        if (!showErrors) return;

        Debug::SetColour(RED);
        std::cout << "[" << GetTime() << "]" << " ERROR - " << output << std::endl;

        // Set it to white again to prevent things that should be white from not being so.
        Debug::SetColour(WHITE);
    }
    void ShowErrors(bool show)
    {
        std::string showString = show ? "Enabled" : "Disabled";
        std::cout << "[Errors " << showString << "]" << std::endl;
        showErrors = show;
    }
    #pragma endregion ErrorFunctions

    std::string Debug::GetTime()
    {
        // TODO: Look into getting this to work without the _CRT_SECURE_NO_WARNINGS flag.
        std::ostringstream outputStream;

        time_t currentTime = time(0);
        struct tm timeStruct;
        char LogTime[80];
        timeStruct = *localtime(&currentTime);
        strftime(LogTime, sizeof(LogTime), "%Y-%m-%d %X", &timeStruct);

        outputStream << LogTime;

        return outputStream.str();
    }

    void Debug::SetColour(int colour)
    {
        HANDLE handle;
        handle = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(handle, colour);
    }
}