#define _CRT_SECURE_NO_WARNINGS
#include "Debug.h"

/// <summary>
/// Logs information on the console.
/// </summary>
void Debug::DebugLog(std::string output)
{
	std::cout << "[" << GetTime() << "]" << " LOG - " << output << std::endl;
}

/// <summary>
/// Logs a warning on the console.
/// </summary>
void Debug::DebugLogWarn(std::string output)
{
    std::cout << "[" << GetTime() << "]" << " WARNING - " << output << std::endl;
}

/// <summary>
/// Logs a error on the console.
/// </summary>
void Debug::DebugLogError(std::string output)
{
    std::cout << "[" << GetTime() << "]" << " ERROR - " << output << std::endl;
}


/// <summary>f
/// Returns the current time as a string.
/// </summary>
/// <returns>Time in the format: Year,Month,Day, Hour,Minute,Second</returns>
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


