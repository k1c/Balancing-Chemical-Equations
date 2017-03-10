#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <string>

using namespace std;
/*
 * Represents an element in the periodic table
 */
class Element
{
public:
    Element();
    Element(int amt_moles);
    Element(double amt_grams);
    // Create an element with the given information from the periodic table file
    void MakeElement(string _name,string _abbreviation,string _atomicNumber,string _mass,string _charge);
    void print();
    // Balance this element with another
    void balance(Element& two);
    // Convert grams to moles
    void grams_to_moles(double amount);

    double find_moles_required(Element two);
    double E_amt_post_reaction(Element two);
    bool limiting_reagent(Element two);

    bool isEven(int number);
    void set_atomic_mass(double num);
    void setCharge(int num);
    void setMoles(double num);
    string toString();

    //Accessor functions
    double get_atomic_mass();
    int get_atoms_needed();
    string get_abbreviation();
    string getName();
    int getAtomicNumber();
    int get_error();
    int getCharge();


private:
    string name;
    string Abbreviation;
    double moles;
    int charge; //e
    int AtomicNumber; //c
    double AtomicMass; //d
    int AtomsNeeded;
    int error;
};

#endif // ELEMENT_H
