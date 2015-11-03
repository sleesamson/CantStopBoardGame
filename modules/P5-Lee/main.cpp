// ==========================================================
// Program 1:  Implement a Dice class          File: main.cpp
// Author: Sam Lee
// ==========================================================

#include "dice.hpp"
#include "game.hpp"
#include "player.hpp"
#include "color.hpp"
#include "column.hpp"
#include "board.hpp"

//Testing Suite for Dice Class
void unit1(){
    ofstream fout;
    fout.open("P2_Lee_Output.txt", ios::out | ios::app);
    Dice d1;                    //default of 6 sides, 2 dice
    Dice d2(4, 1);              //4 sides , 1 dice in set
    Dice d3(8, 4);              //8 sides, 4 dice in set
    Dice d4(6,0);               //No dice in the set

    cout <<"Testing the Dice class" << endl;
    cout <<"outputting to file......" << endl;

    d1.roll();
    fout <<"Test Suite 1: Default parameters of 6 sides and 4 dice in the set."
    << endl << "Values: " << right << setw(7) << d1;

    d2.roll();
    fout <<"Test Suite 2: Parameters of 4 sides and 1 di in the set."
    << endl << "Values: " << right << setw(7) << d2;

    d3.roll();
    fout <<"Test Suite 3: Parameters of 8 sides and 4 dice in the set."
    << endl << "Values: "  << right << setw(7) << d3;

    d4.roll();
    fout <<"Test Suite 4: Parameters of 6 sides and 0 dice in the set."
    << endl << "Values: "  << right << setw(7) << d4;

    fout << "Test Suite 5: Random Range Test, using 6-sided dice " << endl;
    for (int j = 0; j < 5; ++j){
        d1.roll();
        fout << "Values: " << right << setw(7) << d1;
    }
}

//Testing Suite for the Game Class
void unit2(){
    Game cantstop;

    cout << '\n' << "Testing the Game class:" << endl;
    cout << "Values: " << right << setw(7) << cantstop;
}

void unit4(){

    Player *p1 = new Player("Arf", 'o');

    cout <<"Test Case 1: Construct column 4" << endl;
    Column c2(4);
    cout << c2;

    cout <<"\nTest Case 2: startTower()" << endl;
    c2.startTower(p1);
    cout << c2;

    cout << "\nTest Case 3: move() Advance tower one square" << endl;
    c2.move();
    cout << c2;

    cout <<"\nTest Case 4: stop() Replace tower with player's tile" << endl;
    c2.stop();
    cout << c2;

    cout << "\nTest Case 5: advance to last square" << endl;
    c2.startTower(p1);
    cout << c2;
    for (int j=0; j<4; ++j)
        {
            c2.move();
            cout << c2;
        }

    cout << "\nTest Case 6: try to move on last square" << endl;
    if (!c2.move())
        cout << "   Error: Illegal Move" << endl;

    cout <<"\nTest Case 7: Stop at last square to capture" << endl;
    c2.stop();
    cout << c2;

    cout <<"\nTest Case 8: Try to startTower on captured column" << endl;
    if(!c2.startTower(p1))
        cout <<"   Error: Illegal Move" << endl;

    cout <<"\nTest Case 9: New column 2, move() to last square, and bust()" << endl;
    Column c1(2);
    cout<< c1;
    c1.startTower(p1);
    cout << c1;
    c1.move();
    cout << c1;
    c1.move();
    cout << c1;
    c1.bust();
    cout << c1;

    delete p1;

}


int main (void){
    banner();
    //unit1();
    //unit2();
    Game cantstop;
    cantstop.play();

    //unit4();

}
