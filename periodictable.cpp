#include "periodictable.h"
#include "element.h"
#include "compound.h"
#include <QMessageBox>
#include <fstream>
#include <iostream>

PeriodicTable::PeriodicTable()
{
   fill();
}

//Function fill() import all information from the PeriodicTable.txt and build each element individually and place
//each element object in an array.
void PeriodicTable::fill(){
    string name;
    string abbreviation;
    string atomicNumber;
    string mass;
    string charge;

    ifstream build;
    build.open("PeriodicTable.txt");
    if (build.fail()){
        cout<<"Failed to load data from PeriodicTable.txt..."<<endl;
        throw 0;
    }

    for (int i = 0; i < Size; i++){
        build>>name>>abbreviation>>atomicNumber>>mass>>charge;
        table[i].MakeElement(name,abbreviation,atomicNumber,mass,charge);
    }

    build.close();
}

//Prints the entire array.
void PeriodicTable::print(){
    cout<<"TYPE I IONS ONLY"<<endl<<endl;
    for (int i = 0; i < Size; i++){
        table[i].print();
        cout<<endl;
    }
}


void PeriodicTable::information(int atomic_number){
    table[atomic_number - 1].print();                   //atomic_number 1 starts at index 0
}

Element& PeriodicTable::operator [](int index){
    return table[index];
}

Compound operator +(const Element& one, const Element& two){
    return Compound(one,two);
}
