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

    cout << "Enter Player's Name: ";
    getline(cin, name);

    Player* p1 = new Player(name, chooseColor());

    cout << "Name\t" << "Color\t" << "Score\t"<< "Scoreboard" << endl;
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
    }
}

