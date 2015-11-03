// ===================================================================
// Class declaration for Player                              4/30/2013
// Sam Lee                     Program 3               file: player.hpp
// ===================================================================
#pragma once
#include "tools.hpp"
#include "color.hpp"
#include "score.hpp"

class Player {
    private:
        const string name;              //Name of player
        const Color playercolor;        //Color of player
        int score;                      //Number of columns captured
        int scoreboard[3];              //Column ids captured
        Score perm_stats;
        static int count;


    public:
        Player(string pname, Color pcolor, Score s) :
        name(pname), playercolor(pcolor), score(0), scoreboard(), perm_stats(s)
        {
            count++;
        }

        ~Player() {count--;}
        string getName() const {return name;}
        const int* getScoreboard() const {return scoreboard;}
        int getScore() const {return score;}
        Color getColor() const {return playercolor;}
        Score getstats() const {return perm_stats;}
        int getCount() const {return count;}
        bool wonColumn(int colNum);

        ostream& print( ostream& out)const;
};

//--------------------------------------------------------------------
inline ostream& operator << (ostream& out , const Player& P){
    return P.print(out);
}




