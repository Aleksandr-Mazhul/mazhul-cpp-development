#include "Rationalnumber.h"
#include <numeric>

using namespace FractionExtension;

std::string Fraction::toString() const {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}


unsigned int Fraction::gcd(int a, int b) {
    unsigned x = abs(a);
    unsigned y = abs(b);

    if (y == 0) {
        return x;
    }
    if (x == 0) {
        return y;
    }

    int r1 = x % y;
    while (r1 != 0) {
        x = y;
        y = r1;
        r1 = x % y;
    }
    return y;
}

void Fraction::reduce() {
    unsigned g = gcd(numerator, denominator);

    if (g == 1) {
        return;
    }

    numerator /= g;
    denominator /= g;
}

void FractionExtension::Fraction::addWith(Fraction & other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
}

Fraction::Fraction(int numerator, unsigned denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("denominator can't be zero ");
    }
    this->numerator = numerator;
    this->denominator = denominator;

    reduce();
}
