// ===============================================================
// Class functions for color.hpp                   file: color.hpp
// ===============================================================

#include "color.hpp"

const char* const Color::colorNames[6] = {"White", "Orange", "Yellow", "Green", "Blue", "Error"};

//---------------------------------------------------------------------------------------------
Color::Color(char ch){
    ch = toupper(ch);
    switch (ch){
        case 'O': color = ORANGE; break;
        case 'Y': color = YELLOW; break;
        case 'G': color = GREEN; break;
        case 'B': color = BLUE; break;
        default:  color = ERRORS; break;
    }
}
