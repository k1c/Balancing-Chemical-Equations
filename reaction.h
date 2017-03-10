#ifndef REACTION_H
#define REACTION_H
#include "periodictable.h"
#include "compound.h"
#include "equation.h"
#include "element.h"

/*
 * Parent class, facilitates top level user interaction
 * Contains objects of the other classes, and uses them to get the
 * equation for a reaction.
 */
class Reaction
{
public:
    Reaction();
    // Create the elements, gets their information, and balances them
    void make_elements(int E1_atomic_num,double E1_moles,int E2_atomic_num,double E2_moles);

    void print_elements();
    void print_compound();
    void print_equation();
    void print_E1();
    void print_E2();

    // Creates the compound, and the resulting equation
    void make_compound();

    // Return the equation.
    // Behavior is undefined if this is called before make_compound()
    Equation getEquation() const;

private:
    PeriodicTable table;
    Element elemOne;
    Element elemTwo;
    Compound compound;
    Equation equation;
};

#endif // REACTION_H
