#include "compound.h"
#include <iostream>
#include "element.h"
#include <string>

Compound::Compound(){
    c_atomicMass = 0;
    c_moles = 0;
    c_abbreviation = "";
}

Compound::Compound(Element one, Element two)
{
    // Set up the values for the compound based on the given elements. If statement will make sure that
    //the compound is printed in accordance with IUPAC Standards
    if (one.getCharge() < two.getCharge()){
        c_atomicMass = (one.get_atomic_mass() * one.get_atoms_needed()) + (two.get_atomic_mass() * two.get_atoms_needed());
        c_moles = one.find_moles_required(two) + two.find_moles_required(one);
        c_abbreviation = two.get_abbreviation() + "<sub>" + std::to_string(two.get_atoms_needed()) + "</sub>"
                         + one.get_abbreviation() + "<sub>" + std::to_string(one.get_atoms_needed()) + "</sub>";
    } else {
        c_atomicMass = (one.get_atomic_mass() * one.get_atoms_needed()) + (two.get_atomic_mass() * two.get_atoms_needed());
        c_moles = one.find_moles_required(two) + two.find_moles_required(one);
        c_abbreviation = one.get_abbreviation() + "<sub>" + std::to_string(one.get_atoms_needed()) + "</sub>"
                         + two.get_abbreviation() + "<sub>" + std::to_string(two.get_atoms_needed()) + "</sub>";
    }
}

//Prints compound.
void Compound::print_compound(){
    cout<<"Abbreviation: "<<c_abbreviation<<endl;
    cout<<"Atomic Mass: "<<c_atomicMass<<" amu"<<endl;
    cout<<"Moles: "<<c_moles<<endl;
}

//Getter function.
string Compound::get_c_abbreviation(){

    return c_abbreviation;
}
