#ifndef PERIODICTABLE_H
#define PERIODICTABLE_H
#include "element.h"
#include "compound.h"

const int Size = 111;

/*
 * Class to represent a periodic table.
 * Takes elements from a file and stores them in an array of Element objects
 */
class PeriodicTable
{
public:
    PeriodicTable();
    // load the values from the file
    void fill();
    void print();
    // print information for an element
    void information(int atomic_number);

    Element& operator [](int index);

private:

    Element table[Size];
    Compound final;
};


Compound operator +(const Element& one, const Element& two);

#endif // PERIODICTABLE_H
