// ===============================================================
// Class functions for Player                      file:player.cpp
// ===============================================================

#include "player.hpp"

//----increment score, update scoreboard, and return true if 3 columns won (false otherwise)--------
bool Player::wonColumn(int colNum){
    scoreboard[score++] = colNum;
    return score == 3;
}

ostream& Player::print( ostream& out){
    //out << "Name\t" << "Color\t" << "Score\t"<< "Scoreboard" << endl;
    //out << "------------------------------------" << endl;
    out << name << "\t" << playercolor << "\t" << right << setw(5) << score << "\t";
    for (int j=0; j < 3; ++j){
        out << scoreboard[j] << " ";
    }
    out << "\n";
}
