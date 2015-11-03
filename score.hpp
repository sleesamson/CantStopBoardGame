#include "tools.hpp"

#pragma once

class Score {
    private:
        int stats[13];
    public:
        Score(): stats() {}
        ~Score() {}
        void update(int, const int*);
		void update_game(const int* c, int cap);
        void serialize (ostream& out) const;
        istream& realize (istream & in);
        void print( ostream& out) const;
};

inline void operator << (ostream& out , const Score& S){
    S.print(out);
}
