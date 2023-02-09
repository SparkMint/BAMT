#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"

// Text Colour
int WHITE = 15;
int YELLOW = 14;
int RED = 12;

void Debug::Log(std::string output)
{
    Debug::SetColour(WHITE);
	std::cout << "[" << GetTime() << "]" << " LOG - " << output << std::endl;
}

void Debug::LogWarn(std::string output)
{
    Debug::SetColour(YELLOW);
    std::cout << "[" << GetTime() << "]" << " WARNING - " << output << std::endl;

    // Set it to white again to prevent things that should be white from not being so.
    Debug::SetColour(WHITE);
}

void Debug::LogError(std::string output)
{
    Debug::SetColour(RED);
    std::cout << "[" << GetTime() << "]" << " ERROR - " << output << std::endl;

    // Set it to white again to prevent things that should be white from not being so.
    Debug::SetColour(WHITE);
}

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