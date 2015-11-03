// ===================================================================
// Class declaration for color                               4/30/2013
// Sam Lee                     Program 3               file: color.hpp
// ===================================================================
#pragma once;
#include "tools.hpp"

class Color {
    public:
        enum ColorEnum { WHITE, ORANGE, YELLOW, GREEN, BLUE, ERRORS };
        static const char* colorNames[6];

    private:
        ColorEnum color;

    public:
        Color(char ch){
            switch (ch){
                case 'O': color = ORANGE; break;
                case 'Y': color = YELLOW; break;
                case 'G': color = GREEN; break;
                case 'B': color = BLUE; break;
                default:  color = ERRORS; break;
            }
        }

        ColorEnum getColor() {return color;}

        ostream& print( ostream& out){out << colorNames[color] << " ";}
};

inline ostream& operator << (ostream& out , Color& C){
    return C.print(out);
}

