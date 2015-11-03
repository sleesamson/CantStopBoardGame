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
#include "enums.hpp"
#include "exceptions.hpp"

class Game {
    private:
        Board* const b1;
        CList<Player> playerlist;
        FakeDice d1;                   //incorporate one set of dice
        const int* dicepairs;
        GameEnum status;

        void getPlayers();
        const int* rollDice() {return d1.roll();}
        void checkdata(int);
        GameEnum oneTurn(Player *p);

    public:
        Game() : b1(new Board()), playerlist(), d1(), status(BEGUN){
            cout << "\t\t\tWelcome To The Game Can't Stop" << endl;
            getPlayers();
        }
        ~Game() {delete b1;}

        void play();
};







