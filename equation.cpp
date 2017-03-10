#include "equation.h"
#include "compound.h"
#include "element.h"
#include <string>

using namespace std;

Equation::Equation()
{

}

//Puts together the entire end equation as an object of equation that is a string. This is returned to the top level code
//for the interface.
Equation::Equation(Element& one,Element& two,Compound& three){

    equation=one.toString() + " + " + two.toString() + " = " + three.get_c_abbreviation();

    double excess_one = one.E_amt_post_reaction(two);
    double excess_two = two.E_amt_post_reaction(one);
    if (one.get_error() == 1){
        equation = one.toString() + " + " + two.toString() + " = " + one.toString() + " + " + two.toString()
                + "\n" + "No Reaction...";
        return;
    }

    if (excess_one > 0){
        equation = one.toString() + " + " + two.toString() + " = " + three.get_c_abbreviation() + "\n" +
        "Excess element: " + one.getName() + ": " + to_string(excess_one) + " moles" + "\n";
    }else if (excess_two > 0){
        equation = one.toString() + " + " + two.toString() + " = " + three.get_c_abbreviation() + "\n" +
        "Excess element: " + two.getName() + ": " + to_string(excess_two) + " moles" + "\n";
    } else {
            equation = one.toString() + " + " + two.toString() + " = " + three.get_c_abbreviation();
    }

}


void Equation::Print_Equation(){
    cout<<equation;
}

string Equation::toString() const
{
    return equation;
}
