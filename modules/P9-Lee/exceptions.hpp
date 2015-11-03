#include "tools.hpp"
#pragma once

class BadPlayer{    //both color and name in use
    public:
        const string name;
        const char* const color_code;

        BadPlayer(string n, const char* cc) : name(n), color_code(cc) {}

        virtual void print() const {
            cerr << "   Both name and color are already in use\n"
            <<"   You entered " << name << " and " << color_code << ". Please try again! \n";
        }
};

class BadName : public BadPlayer{
    public:
        BadName (string n, const char* cc): BadPlayer(n, cc)  {}
        virtual void print() const{
            cerr << "   You entered " << name << ". That name is already in use. Please try again!\n";
        }
};

class BadColor : public BadPlayer{
    public :
        BadColor(string n, const char* cc): BadPlayer(n, cc) {}
        virtual void print() const{
            cerr << "   You entered " << color_code << ". That color is already in use. Please try again!\n";
        }
};
