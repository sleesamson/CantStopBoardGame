#include "game.hpp"

void Game::getPlayers()
{
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

    parr = new Player*[pcount];     //allocate array for Player pointers

    for (int j = 0; j < pcount; ++j)
    {
        for (;;)
            try{
                checkdata(j);  //read in user's input
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
        int found = count(names_entered, names_entered+k, name);

        if (found > 0)
            badname = true;
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
        cout << "\n" << name << " chose " << color_menu[slot] <<"\n";
        map<string, Score>::iterator it;
        it = game_sb.find(name);
        if (it != game_sb.end())
            parr[k] = new Player(name, c1, it->second);
        else
            parr[k] = new Player(name, c1, Score());

        playerlist += parr[k];
        cout << name  << " has been successfully added to the game. \n";
    }

}

bool Game::rollDice()
{
    dicepairs = dice.roll();

    if(b1.move(dicepairs[0]))
    {
        cout << "Moving Towers in Columns: " << dicepairs[0] << endl;
        if (b1.move(dicepairs[1]))
            cout << "Moving Towers in Columns: " << dicepairs[1] << endl;
        cout << b1;
        return true;
    }
    else
    {
        cout << "You went Bust!\n";
        b1.bust();
        return false;
    }
}

GameEnum Game::stop(Player* p)
{
    b1.stop();
    cout << b1;
    if (p->getScore() == 3)
    {
        cout << *p << " has just won the game! Terminating Game....\n";
        for (int j = 0; j < playerlist.get_count(); ++j)
        {
            game_sb.update(p->getName(), p->getScoreboard());
            game_sb.update("Game", p->getScoreboard());
            p = playerlist.next();
        }
        return DONE;
    }
    return BEGUN;
}

GameEnum Game::quit(Player* p)
{
    b1.bust();						//remove towers on board
    game_sb.update(p->getName(), p->getScoreboard());
    playerlist.remove();
    if (playerlist.get_count() == 0){
        game_sb.update("Game", NULL);
        cout << "All players have resigned... Terminating Game....\n";
        return QUIT;
    }
    return BEGUN;
}

void Game::showCard(Player* p)
{
    cout << "_____________________________________________\n"
    << "SCORE CARD              PLAYER NAME: " << p->getName() << endl
    << "_____________________________________________\n";

    cout << "Columns Captured:     " << p->getScore() << endl;
    cout << "Captured Column IDs:  ";
    for (const int *k = p->getScoreboard(); k < p->getScoreboard() + 3; k++)
        cout << *k << " ";
    cout << "\n\n" << p->getstats();

}

GameEnum Game::oneTurn(Player *p)
{
    int player_action;                              //user input of color selection
    const char* choices[4] = {"1.  Roll", "2.  Stop", "3.  Quit", "4.  Show Scoreboard"};   //user interface menu
    bool stayturn = true;                           //still player's turn?

    b1.startTurn(p);                        //delegate (initialize tow count and tow_array to 0

    while(stayturn)
    {
        cout << "\n\t"<< *p << "'s Turn\n";
        cout << "----------------------------\n";
        for (int k = 0; k < 4; ++k)
            cout << "\t " << choices[k] << endl;
        cout << "-----------------------------\n";
        cout << "\nEnter desired action: ";
        if (cin >> player_action && player_action > 0 && player_action <= 4)
        {
            if (player_action == 1)
                stayturn = rollDice();
            else if (player_action == 2)
            {
                return stop(p);
                break;
            }
            else if (player_action == 3)		//player quits
            {
                return quit(p);
                break;
            }
            else
            {
                showCard(p);
            }
        }
        else
        {
            cout << "Invalid Input. Try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
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
