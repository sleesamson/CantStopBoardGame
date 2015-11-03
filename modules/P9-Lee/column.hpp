// ===================================================================
// Class declaration for Column                              4/30/2013
// Sam Lee                     Program 4              file: column.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"
#include "player.hpp"
#include "color.hpp"

class Column {
    public:
        enum Status{ AVAILABLE, PENDING, CAPTURED };
    private:
        int marker[5];      //marker position
        Status state;       //state of the column
        const int id;         //column number
        const int len;       //length of the column
        Player* player;     //Points to the player in turn;
        static const char* const stateNames[3];  //for output

    public:
        Column(int colNum): marker(), state(AVAILABLE), id(colNum), len(lengths[colNum]){}
        ~Column() {}
        static const int lengths[13];   //lengths of the columns

        Status getState() const {return state;}
        bool startTower(Player* curPlayer);
        bool move();
        Status stop();
        void bust();
        ostream& print( ostream& out) const;

};

inline ostream& operator << (ostream& out , const Column& C){
    return C.print(out);
}
