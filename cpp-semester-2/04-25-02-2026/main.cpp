#include <iostream>
#include "Timer.cpp"

int main()
{
    Timer timer(5);

    while (!timer.isExpired())
    {
        std::cout << "Remaining: "
                  << timer.getRemaining() << "\n";
        timer.tick();
    }

    std::cout << "Timer expired\n";

    return 0;
}