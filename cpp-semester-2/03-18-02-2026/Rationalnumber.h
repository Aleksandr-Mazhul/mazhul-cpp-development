#pragma once
#include <string>

namespace FractionExtension {
    class Fraction {
    public:
        Fraction(int numerator, unsigned denominator);

        std::string toString() const;

        void reduce();

        void addWith(Fraction &);

    private:
        int numerator{1};
        unsigned denominator{1};

        unsigned int gcd(int, int);
    };
}
