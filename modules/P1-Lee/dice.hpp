// ===================================================================
// Class declaration for Dice                              4/10/2013
// Sam Lee                     Program 1                file: dice.cpp
// ===================================================================
#pragma once;
#include "tools.hpp"

class Dice {
    private:
        int nSides;     //number of sides on the dice
        int nDice;      //number of dice in the set
        int* values;    //pseudo-random values of nDice

    public:
        Dice(int sides = 6, int dice = 2);
        ~Dice() { delete [] values; }

        ostream& print( ostream& out);

        const int* roll();
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , Dice& D){
    return D.print(out);
}

//Testing function for the Dice class
void unit1();
