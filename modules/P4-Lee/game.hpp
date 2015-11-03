// ===================================================================
// Class declaration for Game                                4/21/2013
// Sam Lee                     Program 2               file: game.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"
#include "dice.hpp"
#include "player.hpp"
#include "color.hpp"
#include "column.hpp"

class Game {
    private:
        Dice d1;                   //incorporate one set of dice
        Player* Players[4];
        Color* col[4];             //incorporate one color
        Column *c1;

        Color chooseColor();         //unit test for Color class
        void addPlayer();            //unit test for addPlayer class

        void rollDice() {d1.roll();}            //roll the dice

    public:
        Game() : d1() {}
        ~Game() {}

        ostream& print( ostream& out){ out << d1; }

        void play(){
            addPlayer();                    //this unit test will call the Color unit test
        }
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , Game& G){
    return G.print(out);
}





