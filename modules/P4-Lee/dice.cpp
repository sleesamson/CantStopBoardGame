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
    out << endl;
}



