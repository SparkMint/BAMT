#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"

// Text Colour
int WHITE = 15;
int YELLOW = 14;
int RED = 12;
int GREEN = 10;
int GRAY = 6;

namespace Debug 
{
    #pragma region LogFunctions
    bool logsEnabled = true;
    void Debug::Log(std::string output)
    {
        if (!logsEnabled) return;

        Debug::SetColour(WHITE);
        std::cout << "[" << GetTime() << "]" << " LOG - " << output << std::endl;
    }
    void ShowLogs(bool show)
    {
        Debug::SetColour(GRAY);
        std::string showString = show ? "ENABLED" : "DISABLED";
        std::cout << "[LOGS " << showString << "]" << std::endl;
        logsEnabled = show;
        Debug::SetColour(WHITE);
    }
    #pragma endregion LogFunctions

    #pragma region WarningFunctions
    bool warningsEnabled = true;
    void Debug::LogWarn(std::string output)
    {
        if (!warningsEnabled) return;

        Debug::SetColour(YELLOW);
        std::cout << "[" << GetTime() << "]" << " WARN - " << output << std::endl;
        Debug::SetColour(WHITE);
    }
    void Debug::ShowWarns(bool show)
    {
        Debug::SetColour(GRAY);
        std::string showString = show ? "ENABLED" : "DISABLED";
        std::cout << "[WARNINGS " << showString << "]" << std::endl;
        warningsEnabled = show;
        Debug::SetColour(WHITE);
    }
    #pragma endregion WarningFunctions

    #pragma region ErrorFunctions
    bool errorsEnabled = true;
    void Debug::LogError(std::string output)
    {
        if (!errorsEnabled) return;

        Debug::SetColour(RED);
        std::cout << "[" << GetTime() << "]" << " ERROR - " << output << std::endl;
        Debug::SetColour(WHITE);
    }
    void ShowErrors(bool show)
    {
        Debug::SetColour(GRAY);
        std::string showString = show ? "ENABLED" : "DISABLED";
        std::cout << "[ERRORS " << showString << "]" << std::endl;
        errorsEnabled = show;
        Debug::SetColour(WHITE);
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