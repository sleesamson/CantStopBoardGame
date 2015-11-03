// ===================================================================
// Class declaration for Game                                4/21/2013
// Sam Lee                     Program 2               file: game.hpp
// ===================================================================
#pragma once;
#include "dice.hpp"

class Game {
    private:
        Dice* d1;                           //incorporate one set of dice
    public:
        Game() {d1 = new Dice; d1->roll();} //Allocate d1 and roll
        ~Game() {delete d1;}                //Free allocated memory

        ostream& print( ostream& out){ out << *d1;}  //prints out d1 values

};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , Game& G){
    return G.print(out);
}

