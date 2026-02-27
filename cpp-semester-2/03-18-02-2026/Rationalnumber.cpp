#include "Rationalnumber.h"
#include <numeric>
using namespace std;

using namespace FractionExtension;

std::string fraction::toString() const {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

unsigned int fraction::gcd(int a, int b) {
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

void fraction::reduce(int &neminator, int &denominator) {
    unsigned g = gcd(numerator, denominator);

    if (g == 1) {
        return;
    }
c
    numerator /= g;
    denominator /= g;
}

void add(const fraction &lhs, const fraction &rhs){
Fraction result(lhs);
    result.add(lhs);
    /*auto numerator = numerator * rhs.denominator + lhs.numerator * denominator;
    auto denominator *= other.denominator;
    reduce(numerator,denominator);*/
}

fraction::fraction(int numerator, unsigned denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("denominator can't be zero ");
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int gcd = gcd(numerator, denominator);
    this->numerator = numerator / gcd;
    this->denominator = denominator / gcd;

    reduce();
}
