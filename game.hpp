// ===================================================================
// Class declaration for Game                                4/21/2013
// Sam Lee                     Program 2               file: game.hpp
// ===================================================================
#pragma once
#include "tools.hpp"
#include "dice.hpp"
#include "player.hpp"
#include "color.hpp"
#include "column.hpp"
#include "board.hpp"
#include "CList.hpp"
#include "enums.hpp"
#include "exceptions.hpp"
#include "scoreboard.hpp"

class Game {
    private:
        Board b1;                        //Board for the game
        CList<Player> playerlist;        //Circular List of players
        CantStopDice dice;               //incorporate one set of dice
        const int* dicepairs;            //dice pairs chosen by user
        GameEnum status;                 //status of current game
        ScoreBoard game_sb;              //container for pairs
        Player ** parr;                  //array of pointers to Players
        int pcount;                      //user input as to how many players

        void getPlayers();
        bool rollDice();
        GameEnum stop(Player* p);
        GameEnum quit(Player* p);
        void showCard(Player* p);
        void checkdata(int);
        GameEnum oneTurn(Player* p);

    public:
        Game() : b1(), playerlist(), dice(), status(BEGUN), game_sb() {
            cout << "\t\t\tWelcome To The Game Can't Stop" << endl;
            getPlayers();
        }
        ~Game() {
            for (int k = 0; k < pcount; ++k)
                delete parr[k];
            delete [] parr;
        }

        void play();
};







