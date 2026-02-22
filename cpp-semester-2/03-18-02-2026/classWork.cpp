#include <iostream>
#include "RationalFraction.h"
#include "RationalFraction.cpp"

using namespace FractionExtension;

int main() {
    Fraction fraction {1, 4};
    std::cout << toString(fraction) << std::endl;
}