// ===============================================================
// Class functions for Dice                          file:dice.cpp
// ===============================================================

#include "dice.hpp"
//----------------------------------------------------------------
Dice::Dice(int sides, int dice){
    nSides = sides;
    nDice = dice;
    values = new int[nDice];
    srand(time(NULL));
}

//----------------------------------------------------------------
const int* Dice::roll(){
    for (int j = 0; j < nDice; j++){
        values[j] = (rand() % nSides) + 1;
    }
    return values;
}

//----------------------------------------------------------------
ostream& Dice::print(ostream& out){
    for (int j = 0; j < nDice; j++)
        out << values[j] << ' ';
    out << endl << endl;
}

//------------------Test Suite------------------------------------
void unit1(){
    ofstream fout;
    fout.open("P1_Lee_Output.txt", ios::out | ios::app);
    Dice d1;                    //default of 6 sides, 2 dice
    Dice d2(4, 1);              //4 sides , 1 dice in set
    Dice d3(8, 4);              //8 sides, 4 dice in set
    Dice d4(6,0);              //No dice in the set

    cout <<"Printing output to file......" << endl;

    d1.roll();
    fout <<"Test Suite 1: Default parameters of 6 sides and 2 dice in the set."
    << endl << "Values: " << right << setw(7) << d1;

    d2.roll();
    fout <<"Test Suite 2: Parameters of 4 sides and 1 di in the set."
    << endl << "Values: " << right << setw(7) << d2;

    d3.roll();
    fout <<"Test Suite 3: Paramters of 8 sides and 4 dice in the set."
    << endl << "Values: "  << right << setw(7) << d3;

    d4.roll();
    fout <<"Test Suite 4: Paramters of 6 sides and 0 dice in the set."
    << endl << "Values: "  << right << setw(7) << d4;
}
