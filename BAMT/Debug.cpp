#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"
#include "SDL.h"

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
    void Log(std::string output)
    {
        if (!logsEnabled) return;
        Debug::SetColour(WHITE);
        std::cout << "[" << GetTime() << "]" << " LOG - " << output << std::endl;
    }
    void Log(std::string output, void* pointer)
    {
        if (!logsEnabled) return;
        Debug::SetColour(WHITE);
        std::cout << "[" << GetTime() << "]" << " LOG - " << output << " Address: (" << GetPointerAddress(pointer) << ")" << std::endl;
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
    void LogWarn(std::string output)
    {
        if (!warningsEnabled) return;
        Debug::SetColour(YELLOW);
        std::cout << "[" << GetTime() << "]" << " WARN - " << output << std::endl;
        Debug::SetColour(WHITE);
    }
    void LogWarn(std::string output, void* pointer)
    {
        if (!warningsEnabled) return;
        Debug::SetColour(YELLOW);
        std::cout << "[" << GetTime() << "]" << " WARN - " << output << " Address: (" << GetPointerAddress(pointer) << ")" << std::endl;
        Debug::SetColour(WHITE);
    }
    void ShowWarns(bool show)
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
    void LogError(std::string output)
    {
        if (!errorsEnabled) return;

        Debug::SetColour(RED);
        std::cout << "[" << GetTime() << "]" << " ERROR - " << output << std::endl;
        Debug::SetColour(WHITE);
    }
    void LogError(std::string output, void* pointer)
    {
        if (!errorsEnabled) return;

        Debug::SetColour(RED);
        std::cout << "[" << GetTime() << "]" << " ERROR - " << output << " Address: (" << GetPointerAddress(pointer) << ")" << std::endl;
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

    #pragma region LogExtras
    std::string GetTime()
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

    std::string GetPointerAddress(void* pointer)
    {
        std::ostringstream address;
        address << pointer;
        return address.str();
    }

    void SetColour(int colour)
    {
        HANDLE handle;
        handle = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(handle, colour);
    }
    #pragma endregion LogExtras

    #pragma region CommandFunctions
    SDL_Thread* ConsoleThread;
    void CreateCommandThread()
    {
        Log("Starting Command Input Thread...");
        // Null data to make SDL_CreateThread work.
        int data = 0;
        ConsoleThread = SDL_CreateThread(Debug::ConsoleGetCommandInput, "Console Thread", (void*)data);
    }
    void StopCommandThread()
    {
        Log("Waiting for Console Thread to finish before closing...");
        SDL_WaitThread(ConsoleThread, nullptr);
        Log("Console Thread Stopped!");
    }
    int ConsoleGetCommandInput(void* data)
    {
        Log("Command Thread Started!");
        // Runs until the Engine Stops running.
        while (true)
        {
            std::string command;
            std::cin >> command;
            Log("Command Entered: " + command);
        }
        return 0;
    }
    #pragma endregion CommandFunctions
}