#pragma once
#include <string>
#include <numeric>

namespace FractionExtension {
    class fraction {
    public:
        fraction(int numerator, int denominator);

        static void reduce(int neminator, int denominator);

        std::string toString() const;

        static void add(const fraction &lhs, const fraction &rhs);

    private:
        int numerator{1};
        int denominator{1};



    };
}
