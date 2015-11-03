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

void Game::getPlayers()
{
    string name;                //Player's name
    bool won;                   //Won status of player
    int remaining;              //Remaining columns left to win game

    int pcount;

    cout << "Enter number of players (2-4):  ";
    cin >> pcount;

    for (int j = 1; j <= pcount; ++j)
    {
        cout << "Enter Player " << j<< "'s name: ";
        cin >> name >> skipws;
        playerlist.insert(new Player(name, chooseColor()));
    }

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

/*void Game::board_unit(){
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



}*/
void Game::CListUnitTest(){
    Color c1('o');
    Color c2('y');
    Color c3('g');
    Color c4('b');
    Player *p1 = new Player("Arf" ,c1);
    Player *p2 = new Player("Meow", c2);
    Player *p3 = new Player("Moo", c3);
    Player *p4 = new Player("Oink", c4);

    cout << "Test Case 1: Empty List\n";
    cout << "=====================================================\n";
    cout << playerlist;

    cout << "\nTest Case 2: Insert Function\n";
    cout << "=====================================================\n";
    playerlist.insert(p1);
    playerlist.insert(p2);
    playerlist.insert(p3);
    playerlist.insert(p4);
    cout << "Name\t" << "Color\t" << "Score\t"<< "Scoreboard" << endl;
    cout << "------------------------------------" << endl;
    cout << playerlist;

    cout << "\nTest Case 3: Next, Remove, and get_count functions\n";
    cout << "=====================================================\n";
    playerlist.next();
    playerlist.remove();
    cout << "Name\t" << "Color\t" << "Score\t"<< "Scoreboard" << endl;
    cout << "------------------------------------" << endl;
    cout << playerlist;
    cout << "Player count = " << playerlist.get_count() << endl;

    cout << "\nTest Case 4: Full Circle plus one, then first()\n";
    cout << "=====================================================\n";
    for (int j = 0; j < 4; ++j){
    cout << "calling next()....";
    cout << *playerlist.next();
    }
    cout << "calling first()...." << *playerlist.first();

    cout << "\nTest Case 5: Remove all, try first()/next(), then add players again.\n";
    cout << "=====================================================\n";
    cout << "Removing all players........" << endl;
    playerlist.remove();
    playerlist.remove();
    playerlist.remove();
    cout << playerlist;
    cout << "Trying to call next().....\n";
    playerlist.next();
    cout << "Adding all players back again.....\n";

    playerlist.insert(new Player("Arf", c1));
    playerlist.insert(new Player("Meow", c2));
    playerlist.insert(new Player("Moo", c3));
    playerlist.insert(new Player("Oink", c4));
    //playerlist.insert(p3);
    //playerlist.insert(p4);
    cout << playerlist;
}

