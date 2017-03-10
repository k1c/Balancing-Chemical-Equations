#include "reaction.h"


//*******This is the parent class********
Reaction::Reaction()
{

}

//This is used to run the entire reaction.
void Reaction::make_elements(int E1_atomic_num, double E1_moles, int E2_atomic_num, double E2_moles){
    elemOne = table[E1_atomic_num - 1];
    elemOne.setMoles(E1_moles);
    elemTwo = table[E2_atomic_num - 1];
    elemTwo.setMoles(E2_moles);
    elemOne.balance(elemTwo);
}


void Reaction::print_elements(){
    elemOne.print();
    cout<<endl<<endl;
    elemTwo.print();
    cout<<endl;
}


//****************Print functions are used for testing*****************



void Reaction::print_E1(){
    elemOne.print();
}

void Reaction::print_E2(){
    elemTwo.print();
}

Equation Reaction::getEquation() const
{
    return equation;
}

void Reaction::print_compound(){
    compound.print_compound();
}

//Makes the compound.
void Reaction::make_compound(){
    compound = elemOne + elemTwo;
    equation = Equation(elemOne,elemTwo,compound);
}

void Reaction::print_equation(){
    equation.Print_Equation();
}
