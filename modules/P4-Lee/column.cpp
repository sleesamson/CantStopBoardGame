#include "column.hpp"

const int Column::lengths[13] = {0,0,3,5,7,9,11,13,11,9,7,5,3};
const char* Column::stateNames[3] = {"Available", "Pending", "Captured"};

//-----------------start tower at player's current tile position------------------
bool Column::startTower(Player* curPlayer){
    Color::ColorEnum curcol = curPlayer->getColor().getColor();
    if (state == AVAILABLE && marker[Color::WHITE] == 0)
        {
            marker[Color::WHITE] = marker[curcol] + 1;  //advance tower from player's current position
            return true;
        }
    return false;
}

//-------advance tower one square and make changes to state when appropriate--------
bool Column::move(){
    if(state == AVAILABLE){
        marker[Color::WHITE]++;             //advance tower
        if (marker[Color::WHITE] == len)
            state = PENDING;                //pending if on top square
    }
    return state == AVAILABLE;              //can only make move if state available
}

//----------------tower is replaced by the player's tile ---------------------------------
Column::Status Column::stop(Player* curPlayer){
    Color::ColorEnum curcol = curPlayer->getColor().getColor(); //get player's color subscript
    marker[curcol] = marker[Color::WHITE];          //player's tile replaces tower position
    marker[Color::WHITE] = 0;                       //tower is removed from board

    if (marker[curcol] == len){
        state = CAPTURED;                           //column captured if on last square
        curPlayer->wonColumn(id);
    }

    return state;
}

//----------------player did not roll valid dice combo and loses all progress------------
void Column::bust(){
    marker[Color::WHITE] = 0;               //lose all progress
    state = AVAILABLE;
}

//-----------------------------------------------------------------------------------------
ostream& Column::print( ostream& out){
    out << "   " << id  << " " <<left << setw(12) << setfill(' ') << stateNames[state];
    for (int sq_num = 1; sq_num < len+1; ++ sq_num){
        out << "  ";
        for (int k = 0; k < 5; ++k){
            if (marker[k] == sq_num)
                switch(k){
                    case 0: out << 'T'; break;
                    case 1: out << 'O'; break;
                    case 2: out << 'Y'; break;
                    case 3: out << 'G'; break;
                    case 4: out << 'B'; break;
                }

            else
                out << '-';
         }
    }
    out << '\n';
 }
