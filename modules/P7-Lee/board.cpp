#include "board.hpp"

//----Default Constructor: fill backBone based on columns and their length--------
Board::Board(){
    for (int j = 0; j < 13; ++j){
        if (Column::lengths[j] == 0)
            backBone[j] = NULL;
        else{
            backBone[j] = new Column(j);
        }
    }
}

//------------------Destructor: delete Columns-------------------------
Board::~Board() {
    for (int j=0; j<13; ++j){
        delete backBone[j];
    }
}

//----------set Player, initialize tower count and array to 0--------------------
void Board::startTurn(Player* turnPlayer){
    curPlayer = turnPlayer;
    tow_count = 0;

    for (int k = 0; k < 3; ++k)
        tow_columns[k] = 0;
}

//----------move as long as tower(s) available and column state is available---------
//----------return success or failure in a move operation----------------------------
bool Board::move(int column){
    if (backBone[column]->getState() != Column::AVAILABLE)
        return false;
    else{ //available
        if(tow_count < 3 && backBone[column]->startTower(curPlayer)) //tower avail and can start tower
        {
            //backBone[column]->move();
            tow_columns[tow_count++] = column;
        }
        else
            return backBone[column]->move();
    }
}

//--------delegate action to Column class: replace all towers with Player's color--------
void Board::stop(){
    for (int j = 0; j < 3; ++j)
        if (tow_columns[j] != 0)
            backBone[tow_columns[j]]->stop();

//--------delegate bust to Column Class: Lose all tower progress ----------------------
}
void Board::bust(){
    for (int j = 0; j < 3; ++j)
        if (tow_columns[j] != 0)
            backBone[tow_columns[j]]->bust();
}

//--------print the board text display--------------------------------------
ostream& Board::print( ostream& out){
    for (int j=2; j<13; ++j){
        cout << *backBone[j];
    }
}
