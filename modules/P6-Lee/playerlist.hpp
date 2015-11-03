// ===================================================================
// Class declaration for PlayerList                          6/2/2013
// Sam Lee                     Program 6          file: playerlist.hpp
// ===================================================================

#pragma once;
#include "tools.hpp"

class CList;

class Cell {
    private:
        int nSides;     //number of sides on the dice


    public:
        Cell();
        ~Cell() { delete [] values; }

        ostream& print( ostream& out);


};

class CList {
    private:
        int nSides;     //number of sides on the dice


    public:
        CList() {}
        ~CList() {}


        ostream& print( ostream& out);


};
