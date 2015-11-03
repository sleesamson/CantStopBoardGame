// ===================================================================
// Class declaration for Player                              4/30/2013
// Sam Lee                     Program 3               file: player.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"
#include "color.hpp"

class Player {
    private:
        string name;                    //Name of player
        Color playercolor;              //Color of player
        int score;                      //Number of columns captured
        int scoreboard[3];              //Column id captured

    public:
        Player(string pname, Color pcolor) :
            name(pname), playercolor(pcolor), score(0), scoreboard() {}
        ~Player() {}

        int getScore() {return score;}

        Color getColor() {return playercolor;}

        bool wonColumn(int colNum);

        ostream& print( ostream& out);
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , Player& P){
    return P.print(out);
}




