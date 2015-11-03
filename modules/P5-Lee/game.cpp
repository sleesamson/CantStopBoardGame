#include "game.hpp"


//--------------------Color Class Unit Test---------------------------------
//Prompt user to pick color, create object, and return the color CONSTANT
Color Game::chooseColor()
{
    char ch;                                //user input of color selection
    const string menu[4] = {"O: orange", "Y: yellow", "G: green", "B: blue"};       //menu to display to user
    const char* menutitle = "Choose Your Color";                                    //menu title

    for (;;){
        ch = menu_c (menutitle, 4, menu);
        ch = toupper(ch);
        Color c1(ch);
        if (c1.getColor() != Color::ERRORS){
            cout << "\nYou picked: " << c1 << endl;
            return c1;
            break;
        }
        else
            cout << "Error! Invalid Input. Try Again" << endl;
    }

}

void Game::addPlayer()
{
    string name;                //Player's name
    bool won;                   //Won status of player
    int remaining;              //Remaining columns left to win game

    for (;;)
    {
        cout << "Enter Player's Name: ";
        getline(cin, name);
        if (!name.empty())
            break;
        else
            cout << "Name must be at least 1 character. Try Again" << endl;
    }


    p1 = new Player(name, chooseColor());

    /*cout << "Name\t" << "Color\t" << "Score\t"<< "Scoreboard" << endl;
    cout << "------------------------------------" << endl;
    cout << *p1;


    for (int j=2; j<5; ++j){
            won = p1->wonColumn(j);
            cout << "\n\nYou just captured a column! Your score is now: " << p1->getScore() << endl;

        if (won)
            cout << Color::colorNames[4] << " just won the column!"<< endl;
        else
        {
            remaining = 3 - p1->getScore();
            cout << "You need just " << remaining << " more columns to win the game!" << endl;
        }
        cout << *p1;
    }*/
}

void Game::board_unit(){
    cout <<"\nTest Case 1: Default Constructor" << endl;
    cout << "=================================\n";
    b1 = new Board();
    cout << *b1;

    cout <<"\nTest Case 2: startTurn() function" << endl;
    cout << "=================================\n";
    b1->startTurn(p1);

    cout <<"\n\nTest Case 3: move() and stop() function" << endl;
    cout << "==========================================\n";

    for (int k = 0; k<4; ++k)
    {
        cout <<"\nMoving in column 2:" << endl;
        if (!b1->move(2))
            cout << "Illegal Move" << endl;
        else
            cout << *b1;
    }

    for (int j = 0; j < 2; ++j){
        cout <<"\nMoving in column 12:" << endl;
        if (!b1->move(12))
            cout << "Illegal Move" << endl;
        else
            cout << *b1;
    }

    cout <<"\nMoving in column 5:" << endl;
    if (!b1->move(5))
        cout << "Illegal Move" << endl;
    else
        cout << *b1;

    cout <<"\nMoving in column 7:" << endl;
    if (!b1->move(7))
        cout << "Illegal Move" << endl;
    else
        cout << *b1;

    cout << "\nStopping Turn";
    b1->stop();
    cout << '\n' <<*b1;

    cout << "\n Test Case 4: move() and bust() function" << endl;
    cout << "==========================================\n";
    b1->startTurn(p1);
    cout << '\n'<< *b1;

    cout <<"\nMoving in column 5:" << endl;
    if(!b1->move(5))
        cout << "Illegal Move" << endl;
    else
        cout << *b1;

    cout <<"\nSorry! Bust Occured" << endl;
    b1->bust();
    cout << *b1;



}

