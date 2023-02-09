#ifndef DEBUG
#define DEBUG

#include <iostream>
#include <sstream>

namespace Debug 
{
	/// <summary>
	/// Logs information on the console.
	/// </summary>
	void Log(std::string output);

	/// <summary>
	/// Logs a warning on the console.
	/// </summary>
	void LogWarn(std::string output);

	/// <summary>
	/// Logs a error on the console.
	/// </summary>
	void LogError(std::string output);


	/// <summary>f
	/// Returns the current time as a string.
	/// </summary>
	/// <returns>Format: YEAR-MONTH-DAY HOUR:MINUTE:SECOND</returns>
	std::string GetTime();
}
#endif // !DEBUG

