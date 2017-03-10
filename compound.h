#ifndef COMPOUND_H
#define COMPOUND_H
#include <iostream>
#include "element.h"
#include <string>


using namespace std;

class Compound
{
public:
    Compound();
    Compound(Element one, Element two);
    void print_compound();
    string get_c_abbreviation();

private:
    string c_abbreviation;
    double c_atomicMass;
    double c_moles;
};

#endif // COMPOUND_H
