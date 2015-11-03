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
#include "board.hpp"

class Game {
    private:
        Dice d1;                   //incorporate one set of dice
        Player* p1;
        Board* b1;

        Color chooseColor();         //unit test for Color class
        void addPlayer();            //unit test for Player class
        void board_unit();           //unit test for Board Class

        void rollDice() {d1.roll();}            //roll the dice

    public:
        Game() : d1() {}
        ~Game() {delete p1; delete b1;}

        ostream& print( ostream& out){ out << d1; }

        void play(){
            addPlayer();                    //this unit test will call the Color unit test
            board_unit();
        }
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , Game& G){
    return G.print(out);
}





