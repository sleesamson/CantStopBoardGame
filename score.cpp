#include "score.hpp"

void Score::update(int cols_cap, const int* p){
    stats[0]++;             //incrememnt total games played

    if (cols_cap == 3)
        stats[1]++;         //incrememnt if player won game

    for(int j = 0; j < cols_cap; ++j)
    {
        stats[p[j]]++;      //incremement the columns captured
    }
}

void Score::update_game(const int* c, int cap){
    if (c==NULL)
        stats[0]++;
    if (cap == 3)
    {
        stats[0]++;
        stats[1]++;
    }
    for (int k = 0; k < cap; ++k)
    {
        stats[c[k]]++;
    }
}
//-----write player's stat to stream-------
void Score::serialize (ostream& out) const{
    for (int j = 0; j < 13; ++j)
        out << stats[j] << " ";
    out << "\n";
}

istream& Score::realize (istream & in)
{
    return in >> stats[0] >> stats[1] >> stats[2] >> stats[3] >> stats[4] >> stats[5] >>
    stats[6] >> stats[7] >> stats[8] >> stats[9] >> stats[10] >> stats[11] >> stats[12] >> ws;

}

void Score::print( ostream& out) const {
        out << "Total Games Played:   " << stats[0] << endl
        << "Total Games Won:      " << stats[1] << endl
        << " \nColumn Statistics(Total Times Captured)\n";
    for (int j = 2; j < 13; ++j)
    {
        out  << "    Column "<< left << setw(11) << setfill(' ') << j
        << stats[j] << endl;
    }
}
