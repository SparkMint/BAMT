#include "TickTimer.h"
#include "Debug.h"

TickTimer::TickTimer()
{
	Debug::Log("Tick Timer Instance Created.");
	startTicks = 0;
}

void TickTimer::ResetTimer()
{
	startTicks = SDL_GetTicks();
}

int TickTimer::GetTicks() const
{
	return (SDL_GetTicks() - startTicks);
}
