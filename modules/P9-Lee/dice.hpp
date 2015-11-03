// ===================================================================
// Class declaration for Dice                              4/10/2013
// Sam Lee                     Program 1                file: dice.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"
#define FILE "fakedicefile.txt"

class Dice {
    protected:
        int nSides;         //number of sides on the dice
        int nDice;          //number of dice in the set
        int* const values;          //pseudo-random values of nDice

    public:
        Dice(int sides = 6, int dice = 4);
        ~Dice() { delete [] values; }

        virtual const int* roll();
        ostream& print( ostream& out) const;
};
//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , const Dice& D){
    return D.print(out);
}

class CantStopDice : public Dice{
    protected:
        int pair_totals[2];
    public:
        CantStopDice() : Dice(), pair_totals() {}
        ~CantStopDice() {}
        virtual const int* roll();
};

class FakeDice : public CantStopDice{
    private:
        ifstream fin;
    public:
        FakeDice() : CantStopDice() {fin.open(FILE, ifstream::in);}
        ~FakeDice() {fin.close();}
        const int* roll();
};


