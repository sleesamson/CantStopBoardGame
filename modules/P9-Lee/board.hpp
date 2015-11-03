// ===================================================================
// Class declaration for Column                              5/22/2013
// Sam Lee                     Program 5              file:  board.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"
#include "column.hpp"


class Board {
    private:
        int tow_count;          //towers in use
        int tow_columns[3];     //tower locations
        Column* backBone[13];   //points to columns
        Player* curPlayer;      //current player

    public:
        Board();
        ~Board();
        void startTurn(Player* turnPlayer);
        bool move(int column);
        void stop();
        void bust() const;
        ostream& print( ostream& out)const;
};

inline ostream& operator << (ostream& out , Board& B){
    return B.print(out);
}
