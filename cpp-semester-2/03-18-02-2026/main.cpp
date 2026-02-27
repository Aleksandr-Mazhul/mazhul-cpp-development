#include <iostream>
#include "Rationalnumber.cpp"

using namespace FractionExtension;

int main()
{
    fraction fraction(45, 90);
    fraction fraction1(-14, 7);
    std::cout << fraction1.toString() << std::endl;
    std::cout <<fraction.toString() << std::endl;
    fraction.addWith(fraction1);
    std::cout << fraction1.toString() << std::endl;
    std::cout << fraction.toString() << std::endl;

}