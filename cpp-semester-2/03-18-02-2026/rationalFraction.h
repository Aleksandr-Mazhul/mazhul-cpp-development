#ifndef _VSCODE_RATIONALFRACTION_H
#define _VSCODE_RATIONALFRACTION_H

#endif //_VSCODE_RATIONALFRACTION_H

#pragma once
#include <string>

 namespace FractionExtension {
     struct Fraction {
         int numerator {1};
         unsigned denominator {1};
     };

     std::string toString (const Fraction&);

     unsigned int gcd(int , int);

     void reduce(Fraction&);

 }


class Fraction {
     int size;
     int power = 100;
     std::string toString (const Fraction&);
 }