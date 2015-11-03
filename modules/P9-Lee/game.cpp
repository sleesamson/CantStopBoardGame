#include "game.hpp"

void Game::getPlayers()
{
    int pcount;             //number of players in game
    const string name;      //name of a player

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

    for (int j = 0; j < pcount; ++j)
    {
        for (;;)
            try{
                checkdata(j);
                break;
            }
            catch(bad_alloc ba) {cerr << "  Failed Allocation of Player: " << ba.what() << '\n';}
            catch(BadPlayer &bp) { bp.print(); }
            catch(BadName &ba) {ba.print();}
            catch(BadColor &bc) {bc.print();}
            catch(...) {cerr << "   Invalid Input. Try again!\n";}

    }

}

void Game::checkdata(int k)
{
    //find(arr(first), last, value
    const char* color_menu[4] = {"O: Orange", "Y: Yellow", "G: Green", "B: Blue"};
    static bool mask[4] = {true, true, true, true};
    char ch;
    bool badname = false;
    bool badcolor = false;
    string name;
    static string names_entered[4];
    int slot;

    cout << "\n    Color options\n";
    cout<< "------------------------------\n";
    for (int j = 0; j < 4; ++j)
        if (mask[j])
            cout << '\t' << color_menu[j] << endl;
    cout<< "------------------------------\n";
    cout << "Player "<< k+1 << ", Enter a color option followed by a name: ";
    cin >> ch;
    cin >> ws;
    getline(cin, name);


    if (k == 0)
        names_entered[k] = name;
    else{
        for (int p = k-1; p >= 0; --p)
            if (name == names_entered[p]) {
                badname = true;
            }
            else
                names_entered[k] = name;
    }

    switch(toupper(ch))
    {
        case 'O':
            slot = 0;
            if(!mask[slot])
                badcolor = true;
            else
                mask[slot] = false;
            break;
        case 'Y':
            slot = 1;
            if(!mask[slot]) {
                badcolor = true;
            }
            else mask[slot] = false;
            break;
        case 'G':
            slot =2;
            if(!mask[slot]){
                badcolor = true;
            }
            else mask[slot] = false;
            break;
        case 'B':
            slot =3;
            if(!mask[slot]){
                badcolor = true;
            }
            else mask[slot] = false;
            break;
    }


    if (badcolor && !badname)
    {
        throw BadColor(name, color_menu[slot]);
    }
    if (badname && !badcolor) {
        mask[slot] = true;
        throw BadName(name, color_menu[slot]);
    }
    if (badname && badcolor) {
        throw BadPlayer(name, color_menu[slot]);
        mask[slot] = true;
    }

    Color c1(ch);

    if(c1.getColor() == Color::ERRORS) throw "Invalid";
    else{
        cout << "\n" << name << " picked: " << c1 << "\n";
        playerlist.insert(new Player(name, c1));
        cout << name << " (" << c1 <<")" << " has been successfully added to the game. \n";
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
                if (p->getScore() == 3){
                    cout << *p << " has just won the game! Terminating Game....\n";
                    return DONE;
                }
                break;
            }
            else
            {
                b1->bust();
                playerlist.remove();
                if (playerlist.get_count() == 0){
                    cout << "All players have resigned... Terminating Game....\n";
                    return QUIT;
                }
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
    return BEGUN;
}

void Game::play(){

    Player* p;
    cout << "\nStarting Game......\n\n";
    p = playerlist.first();
    status = oneTurn(p);

    while (status == BEGUN)
    {
        status = oneTurn(playerlist.next());
    }
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
