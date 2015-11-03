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
#include "CList.hpp"


void unit1();           //unit test for Dice class
void unit4();           //unit test for Column class
void unit_derived_dice();   //unit test for the CantStopDice

int main (void){

    banner();
    const int * pairptr;
    //unit1();
    //unit2();

    //Game cantstop;
    //cantstop.play();


    //unit4();

    unit_derived_dice();
    bye();

}

//Testing Suite for Dice Class
void unit1(){
    Dice d1;                    //default of 6 sides, 2 dice
    Dice d2(4, 1);              //4 sides , 1 dice in set
    Dice d3(8, 4);              //8 sides, 4 dice in set
    Dice d4(6,0);               //No dice in the set

    cout <<"Testing the CantStopDice Class" << endl;

    d1.roll();
    cout <<"Test Suite 1: Default parameters of 6 sides and 4 dice in the set."
    << endl << "Values: " << right << setw(7) << d1;

    d2.roll();
    cout <<"Test Suite 2: Parameters of 4 sides and 1 di in the set."
    << endl << "Values: " << right << setw(7) << d2;

    d3.roll();
    cout <<"Test Suite 3: Parameters of 8 sides and 4 dice in the set."
    << endl << "Values: "  << right << setw(7) << d3;

    d4.roll();
    cout <<"Test Suite 4: Parameters of 6 sides and 0 dice in the set."
    << endl << "Values: "  << right << setw(7) << d4;

    cout << "Test Suite 5: Random Range Test, using 6-sided dice " << endl;
    for (int j = 0; j < 5; ++j){
        d1.roll();
        cout << "Values: " << right << setw(7) << d1;
    }
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

void unit_derived_dice(){
    const int *ptr;
    CantStopDice d1;

    cout << "CantStopDice Unit Test............" << endl;
    ptr = d1.roll();
    cout << "Higher priority pair total (first array elemnt) = " << *ptr;
    ptr++;
    cout <<"\nLower priority pair total (second array element) = " << *ptr;

    cout << "\n\nFakeDice Unit Test............" << endl;
    FakeDice d2;
    for (int j=1;j<=5;++j)
    {

        ptr = d2.roll();
        if(ptr != NULL)
        {
            cout << "Line " << j << " pair totals = " << *ptr << " ";
            ptr ++;
            cout << *ptr << endl;
        }
    }
}
