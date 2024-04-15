#include "Time.h"
Time* Time::_instance = nullptr;
Time::Time()
{
    UpdateDeltaTime();
    timeScale = 1;
}

float Time::SetTimeScale(float scale)
{
    timeScale = scale;
    return timeScale;
}

float Time::GetDeltaTime() const
{
    return deltaTime * timeScale;
}

float Time::UpdateDeltaTime()
{
  
    deltaTime = (SDL_GetTicks() - (float)(previousFrameTicks)) / 1000;
    previousFrameTicks = SDL_GetTicks();
    return deltaTime;
}
