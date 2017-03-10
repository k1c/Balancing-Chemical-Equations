#include "element.h"
#include <fstream>
#include <iostream>
#include <string>

Element::Element()
{
    moles = 1;
    AtomsNeeded = 0;
    error = 0;  //error is default 0. Will go to 1 if BOTH elements have a positive charge, negative charge or if one
                // or both have a charge of 0. This means that there will be no reaction.
}

void Element::MakeElement(string _name,string _abbreviation,string _atomicNumber,string _mass,string _charge){//builds an element
    name = _name;
    Abbreviation = _abbreviation;
    AtomicNumber = atoi(_atomicNumber.c_str()); //c converts string to int
    AtomicMass = atof(_mass.c_str()); //d converts string to double
    charge = atoi(_charge.c_str()); //e converts string to int
    error = 0;
}

void Element::print(){
    cout<<"Name: "<<name<<endl;
    cout<<"Abbreviation: "<<Abbreviation<<endl;
    cout<<"Atomic Number: "<<AtomicNumber<<endl;
    cout<<"Atomic Mass: "<<AtomicMass<<" amu"<<endl;
    cout<<"Charge: "<<charge<<endl;
    cout<<"Atoms Needed "<<AtomsNeeded;
}


//Converts grams to moles but is not used in this version at the top level.
void Element::grams_to_moles(double amount){

    moles = amount/AtomicMass;

}

//Finds the amount of moles required for the reaction involving the two chosen elements. Calculated in the standard way.
//Can be calculated only after balance(Element& two) has run.
double Element::find_moles_required(Element two){
    double amt_req;
    double e1_atoms = AtomsNeeded;
    double e2_atoms = two.AtomsNeeded;
    if (e1_atoms == e2_atoms && moles > two.moles){
        amt_req = (e1_atoms / e2_atoms) * two.moles;
    } else {
    amt_req = (e1_atoms / e2_atoms) * two.moles;
    }
    return amt_req;
}

//Amount of an element left over after the reaction. This can only be calculated after balance(Element& two).
 double Element::E_amt_post_reaction(Element two){
    double required = find_moles_required(two); //required is the amount of moles required for Element 1.
    bool left_over = limiting_reagent(two);
    double amount = 0;
    if (left_over){
        amount = 0;
        return amount;
    }
    amount = moles - required;
    return amount;
 }

//Balances two inputs.
void Element::balance(Element& two){
    int c;  //remainder of E1/E2
    int d;  //remainder of E2/E1
    if ((charge > 0 && two.charge > 0) || (charge < 0 && two.charge < 0) || (charge == 0 || two.charge == 0)){
        AtomsNeeded = 1;
        two.AtomsNeeded = 1;
        error = 1;
        return;
    }
    int E1 = abs(charge);
    int E2 = abs(two.charge);
    c = E1 % E2; //c is the remainder from (charge / two.charge) because if it is zero we can use 1 as the empirical number
                //for the ratio of atoms needed. Same with d. if the ratio is imperfect and a fraction would be left then
                //the emperical numbers for the ratio of atoms needed will not have a one in it. (ex: 2:3)
    d = E2 % E1;
    if (E1 > E2 && c == 0){
        two.AtomsNeeded = E1 / E2;
        AtomsNeeded = 1;
    }else if (E1 > E2){
        AtomsNeeded = E2;
        two.AtomsNeeded = E1;
    }else if (E1 < E2 && d == 0){
        AtomsNeeded = E2 / E1;
        two.AtomsNeeded = 1;
    }else if (E1 < E2){
        two.AtomsNeeded = E1;
        AtomsNeeded = E2;
    }
    else {
        AtomsNeeded = 1;
        two.AtomsNeeded = 1;
    }
    //This loop is used to reduce the ratio of atoms needed down to the emperical ratio.
    //ex: (2:4) will go to (1:2).
    while (isEven(AtomsNeeded) && isEven(two.AtomsNeeded)){
        AtomsNeeded = AtomsNeeded / 2;
        two.AtomsNeeded = two.AtomsNeeded / 2;
    }
}


bool Element::limiting_reagent(Element two){
    if (moles >= find_moles_required(two)){
        return false;
    }
    return true;                                //if true, it returns limiting reagent
}

//Returns true if the number is even.
bool Element::isEven(int number){

    if(number%2==0){
        return true;            //number is even
    }

    return false;

}


//**************SETTER AND GETTER FUNCTIONS BELOW*****************



void Element::setMoles(double num){
    moles = num;
}

void Element::setCharge(int num){
    charge = num;
}

void Element::set_atomic_mass(double num){
    AtomicMass = num;
}

double Element::get_atomic_mass(){
    return AtomicMass;
}

int Element::get_atoms_needed(){
    return AtomsNeeded;

}

string Element::getName(){
    return name;
}

int Element::getAtomicNumber()
{
    return AtomicNumber;
}

 string Element::get_abbreviation(){

     return Abbreviation;
 }

 string Element::toString(){

     return to_string(AtomsNeeded) + Abbreviation;

 }

 int Element::get_error(){
     return error;
 }

 int Element::getCharge()
 {
     return charge;
 }
