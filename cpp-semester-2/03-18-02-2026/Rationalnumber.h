#pragma once
#include <string>
#include<stdexcept>

namespace FractionExctesion {
    class Fraction
    {
    public:
        Fraction(int numerator, unsigned denominator);
        std::string toString() const;
        void reduce();
        void addWith(Fraction& const);
    private:
        int numerator{ 1 };
        unsigned denominator{ 1 };
        unsigned int gcd(int, int);

    };



}