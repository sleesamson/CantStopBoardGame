// ===================================================================
// Class declaration for Player                              4/30/2013
// Sam Lee                     Program 3               file: player.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"
#include "color.hpp"

class Player {
    private:
        const string name;              //Name of player
        const Color playercolor;              //Color of player
        int score;                      //Number of columns captured
        int scoreboard[3];              //Column ids captured

    public:
        Player(string pname, Color pcolor) :
            name(pname), playercolor(pcolor), score(0), scoreboard() {}
        ~Player() {}

        int getScore() const {return score;}
        Color getColor() const {return playercolor;}
        bool wonColumn(int colNum);
        ostream& print( ostream& out)const;
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , const Player& P){
    return P.print(out);
}




