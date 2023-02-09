#ifndef DEBUG
#define DEBUG

#include <iostream>
#include <chrono>
#include <sstream>

namespace Debug 
{
	void DebugLog(std::string output);
	void DebugLogWarn(std::string output);
	void DebugLogError(std::string output);

	std::string GetTime();
}

#endif // !DEBUG

