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
#include "CList.hpp"

class Game {
    private:
        CantStopDice d1;                   //incorporate one set of dice
        CList<Player> playerlist;
        Board* b1;

        Color chooseColor();         //unit test for Color class
        void getPlayers();           //unit test for Player class
        void board_unit();           //unit test for Board Class

        void rollDice() {d1.roll();}            //roll the dice
        void CListUnitTest();

    public:
        Game() : d1(), playerlist() {
            //getPlayers();
            //CListUnitTest();
        }
        ~Game() {//delete b1;
        }



        void play(){

            //board_unit();
        }
};







