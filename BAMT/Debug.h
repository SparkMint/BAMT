#ifndef DEBUG
#define DEBUG

#include <iostream>
#include <sstream>
#include "windows.h"

namespace Debug
{
	/// <summary>
	/// Logs information on the console.
	/// </summary>
	void Log(std::string output);

	extern bool showLogs;
	void ShowLogs(bool showLogs);

	/// <summary>
	/// Logs a warning on the console.
	/// </summary>
	void LogWarn(std::string output);

	extern bool showWarnings;
	void ShowWarnings(bool showWarnings);

	/// <summary>
	/// Logs a error on the console.
	/// </summary>
	void LogError(std::string output);

	extern bool showErrors;
	void ShowErrors(bool showErrors);


	/// <summary>
	/// Returns the current time as a string.
	/// </summary>
	/// <returns>Format: YEAR-MONTH-DAY HOUR:MINUTE:SECOND</returns>
	std::string GetTime();

	/// <summary>
	/// Changes the colour of text.
	/// </summary>
	/// <param name="colour">The colour to change it into.</param>
	void SetColour(int colour);
}
#endif // !DEBUG