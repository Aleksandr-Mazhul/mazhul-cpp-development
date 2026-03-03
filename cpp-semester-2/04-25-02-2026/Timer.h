#pragma once

class Timer
{
public:
    explicit Timer(int seconds);

    void tick();
    void reset(int seconds);

    bool isExpired() const;
    int getRemaining() const;

private:
    int remainingSeconds{0};
};