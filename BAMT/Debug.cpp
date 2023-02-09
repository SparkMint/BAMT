#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"


void Debug::Log(std::string output)
{
	std::cout << "[" << GetTime() << "]" << " LOG - " << output << std::endl;
}

void Debug::LogWarn(std::string output)
{
    std::cout << "[" << GetTime() << "]" << " WARNING - " << output << std::endl;
}

void Debug::LogError(std::string output)
{
    std::cout << "[" << GetTime() << "]" << " ERROR - " << output << std::endl;
}

std::string Debug::GetTime()
{
    std::ostringstream outputStream;

    time_t currentTime = time(0);
    struct tm tstruct;
    char LogTime[80];
    tstruct = *localtime(&currentTime);
    strftime(LogTime, sizeof(LogTime), "%Y-%m-%d %X", &tstruct);

    outputStream << LogTime;

    return outputStream.str();
}