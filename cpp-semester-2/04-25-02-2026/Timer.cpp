#include "Timer.h"
#include <stdexcept>

Timer::Timer(int seconds)
{
    if (seconds < 0)
        throw std::invalid_argument("Time cannot be negative");

    remainingSeconds = seconds;
}

void Timer::tick()
{
    if (remainingSeconds > 0)
        --remainingSeconds;
}

void Timer::reset(int seconds)
{
    if (seconds < 0)
        throw std::invalid_argument("Time cannot be negative");

    remainingSeconds = seconds;
}

bool Timer::isExpired() const
{
    return remainingSeconds == 0;
}

int Timer::getRemaining() const
{
    return remainingSeconds;
}