#include "RationalFraction.h"

// using namespace FractionExtension;

std::string FractionExtension::toString(const Fraction &fraction) {
    return std::to_string(fraction.numerator) + "/" + std::to_string(fraction.denominator);
}

unsigned int gcd(int a, int b) {
    unsigned x = abs(a);
    unsigned y = abs(b);

    if (y == 0) {
        return x;
    }
    if (x == 0) {
        return y;
    }


    int r1 = x % y;
    while (r1 != 0)
    {
        x = y;
        y = r1;
        r1 = x % y;
    }
    return y;
}

void FractionExtension::(Fraction&) {

}

std::string Fraction::toString(const Fraction &) {
}
