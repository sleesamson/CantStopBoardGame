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
    out << name  << " "<< playercolor;
}
