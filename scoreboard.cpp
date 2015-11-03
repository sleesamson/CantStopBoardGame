#include "scoreboard.hpp"

//------------------read in the file and insert into map----------------------
void ScoreBoard::realize()
{
    ifstream fin;
    string name;

    fin.open(INF, ifstream::in | ifstream::app);
    if(!fin) fatal("Cannot open file %s", INF);

    //check for empty file
    fin.seekg(0, ios::end);
    int length = fin.tellg();
    if (length != 0)
    {
        fin.seekg(0, ios::beg);
        while(true)
        {
            Score s;
            fin >> name;
            s.realize(fin);
            this->insert(SBPair(name, s));
            if(fin.eof())
                break;
        }
    }
	else {this->insert(SBPair("Game", Score()));}
}

//-------iterate through map and delegate to Score class(print to file)------------------
void ScoreBoard::serialize(){
    SBoard::iterator k;

    ofstream fout;
    fout.open(OUTF, ofstream::out);
    for (k = this->begin(); k!= this->end(); ++k){
        fout << k->first << " ";
        k->second.serialize(fout);
    }
}

//--------------------Print scores stored in map----------------------------------------
void ScoreBoard::print(){
    SBoard::iterator k;
    for (k = this->begin(); k!= this->end(); ++k)
    {
        cout << k->first <<" " << k->second;
    }
}

//-------------update stats of Game and Player------------------------------------------
void ScoreBoard::update(const string Name, const int* column){
    int j = 0;						//counter
    SBoard::iterator k;				//map iterator

	if (column != NULL)
		for (int p = 0; p < 3; ++p)
			if (column[p] > 0)         //search array for # of columns captured
				j++;				   //keep count and later passed in to update

	if(Name == "Game")			//"Game" , NULL arguments when there is no winner (all resigned)
	{
		k = this->find("Game");
		k->second.update_game(column, j);
	}
	else
	{
		k = this->find(Name);			//find the name in the map
		if (k == this->end())
		{
			this->insert(SBPair( Name, Score() ));  //insert player in map if first time name
		}

		k = this->find(Name);
		k->second.update(j, column);   //update player's lifetime stats
	}
}
