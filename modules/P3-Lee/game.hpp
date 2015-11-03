// ===================================================================
// Class declaration for Game                                4/21/2013
// Sam Lee                     Program 2               file: game.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"
#include "dice.hpp"
#include "player.hpp"
#include "color.hpp"

class Game {
    private:
        Dice d1;                   //incorporate one set of dice
        Player p1;                 //incorporate one player
        Color::ColorEnum col;      //incorporate one color

        Color::ColorEnum chooseColor();         //unit test for Color class
        void addPlayer();                       //unit test for addPlayer class

        void rollDice() {d1.roll();}            //roll the dice

    public:
        Game() : d1(), p1("Sam", Color::ORANGE) {}
        ~Game() {}

        ostream& print( ostream& out){ out << d1 << p1; }

        void play(){
            addPlayer();                    //this unit test will call the Color unit test
        }
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , Game& G){
    return G.print(out);
}





