#include "tools.hpp"
#include "score.hpp"
#pragma once
#define SBoard  map<string, Score>
#define SBPair  pair<string, Score>
#define INF "1strun_scoreboard.txt"
#define OUTF "1strun_scoreboard.txt"

class ScoreBoard: public SBoard{
    public:
        ScoreBoard(){realize();}
        ~ScoreBoard(){serialize();}

        void realize();
        void serialize();
        void print();
        void update(const string Name, const int* column);
};
