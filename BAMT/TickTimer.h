#ifndef BAMT_TICK_TIMER
#define BAMT_TICK_TIMER

#include"SDL.h"

/// <summary>
/// This class makes sure that Ticks are a specified time
/// to prevent game logic acting oddly.
/// </summary>
class TickTimer 
{
	private:
		int startTicks;

	public:
		TickTimer();

		/// <summary>
		/// Sets start ticks to the current time.
		/// </summary>
		void ResetTimer();

		/// <returns>Amount of ticks that has passed since the timer was reset.</returns>
		int GetTicks();
};

#endif // !BAMT_TICK_TIMER
