#include "game.hpp"

void Game::getPlayers()
{
    string name;                //Player's name
    int pcount;
    char ch;
    char* color_menu[4] = {"O: Orange", "Y: Yellow", "G: Green", "B: Blue"};
    bool mask[4] = {true, true, true, true};
    char choicemask[4];

    for(;;){
        cout << "\nEnter number of players (2-4):  ";
        if (cin >> pcount && pcount > 1 && pcount <= 4)
            break;
        else {
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    for (int j = 1; j <= pcount; ++j){

        cout << "\nEnter Player " << j<< "'s name: ";
        cin.ignore(1);
        getline(cin, name);

        for(;;){
            cout << "\nChoose a Colored Tile\n";
            cout << "-----------------------------\n";

            for (int k = 0; k < 4; ++k){
                if (mask[k])
                    cout << '\t' <<color_menu[k] << endl;
            }
            cout << "-----------------------------";
            cout << "\nEnter code of desired color: ";
                if (cin >> ch){
                    ch = toupper(ch);
                        if (ch == 'O')
                        {
                            if (!mask[0]){
                                cout<<"Orange Already Assigned!\n";
                                continue;
                                continue;
                            }
                            mask[0] = false;
                        }
                        else if (ch == 'Y'){
                            if (!mask[1]){
                                cout<<"Yellow Already Assigned!\n";
                                continue;
                                continue;
                            }
                            mask[1] = false;
                        }

                        else if (ch == 'G'){
                            if (!mask[2]){
                                cout<<"Green Already Assigned!\n";
                                continue;
                                continue;
                            }
                            mask[2] = false;
                        }
                        else if (ch == 'B'){
                            if (!mask[3]){
                                cout<<"Blue Already Assigned!\n";
                                continue;
                                continue;
                            }
                            mask[3] = false;
                        }

                        Color c1(ch);
                        if (c1.getColor() != Color::ERRORS)
                        {
                            cout << "\n" << name << " picked: " << c1 << endl;
                            playerlist.insert(new Player(name, c1));
                            break;
                        }
                        else
                            cout << "Error! Invalid Input. Try Again" << endl;
                }
        }
    }
}

GameEnum Game::oneTurn(Player *p)
{
    int player_action;                              //user input of color selection
    b1->startTurn(p);

    const char* choices[3] = {"1.  Roll", "2.  Stop", "3.  Quit"};


    for(;;)
    {
        cout << "\n\t"<< *p << "'s Turn\n";
        cout << "----------------------------\n";
        for (int k = 0; k < 3; ++k)
            cout << "\t " << choices[k] << endl;
        cout << "-----------------------------\n";
        cout << "\nEnter desired action: ";
        if (cin >> player_action && player_action > 0 && player_action <= 3)
        {
            if (player_action == 1)
            {
                dicepairs = rollDice();
                if(b1->move(dicepairs[0]))
                {
                    cout << "Moving Towers in Columns: " << dicepairs[0] << endl;
                    if (b1->move(dicepairs[1]))
                        cout << "Moving Towers in Columns: " << dicepairs[1] << endl;
                    cout << *b1;
                }
                else
                {
                    cout << "You went Bust!\n";
                    b1->bust();
                    break;
                }
            }
            else if (player_action == 2)
            {
                b1->stop();
                cout << *b1;
                break;
            }
            else
            {
                b1->bust();
                playerlist.remove();
                break;
            }
        }
        else
        {
            cout << "Invalid Input. Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
    }
}

void Game::play(){

    Player* p;
    cout << "\nStarting Game......\n\n";
    oneTurn(playerlist.first());
    oneTurn(playerlist.next());
    oneTurn(playerlist.next());

    /*while (status == BEGUN){
        p = playerlist.first();
        if(playerlist.get_count() == 0)
        {
            cout << "All players have resigned!!  Terminating Game.......\n";
            status = QUIT;
        }
        else
        {
            oneTurn(p);
            if(p->getScore() == 3){
                cout << *p << "HAS WON THE GAME!! TERMINATING GAME....\n";
                status = DONE;
            }
            else
                oneTurn(playerlist.next());
        }
    }*/
}


/*
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
}*/
