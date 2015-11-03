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
        Color::ColorEnum color;         //Color of player
        int score;                      //Number of columns captured
        int scoreboard[3];              //Column id captured

    public:
        Player(string pname, Color::ColorEnum pcolor) :
            name(pname), color(pcolor), score(0), scoreboard() {}
        ~Player() {}

        int getScore() {return score;}

        Color::ColorEnum getColor() {return color;}

        bool wonColumn(int colNum);

        ostream& print( ostream& out){
            out << name << "\t" << Color::colorNames[color] << "\t" << right << setw(5) << score << "\t";
            for (int j=0; j < 3; ++j){
                out << scoreboard[j] << " ";
            }
        }
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , Player& P){
    return P.print(out);
}




