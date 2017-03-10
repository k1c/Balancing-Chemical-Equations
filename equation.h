#ifndef EQUATION_H
#define EQUATION_H
#include "element.h"
#include "compound.h"
#include "periodictable.h"
#include <string>

/*
 * Holds the equation as a string, made up of two elements and the resulting compound.
 * This string is the final result displayed
 */
class Equation
{
public:
    Equation();
    Equation(Element& one,Element& two, Compound& three);
    void Print_Equation();

    string toString() const;

private:
    string equation;
};

#endif // EQUATION_H
