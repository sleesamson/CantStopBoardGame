// ===============================================================
// Class functions for Dice                          file:dice.cpp
// ===============================================================

#include "dice.hpp"

//----------------------------------------------------------------
const int* Dice::roll() {
    for (int j = 0; j < nDice; j++){
        values[j] = (rand() % nSides) + 1;
    }

    return values;
}

//----------print values + text GUI of dice rolled----------------------------
ostream& Dice::print(ostream& out)const{
    string dot(29, ' ');

    for (int j = 0; j < nDice; j++)
    {
        switch (values[j])
        {
            case 1:
                if (j == 0) dot[4] = 'o';
                else if (j == 1) dot[11] = 'o';
                else if (j == 2) dot[18] = 'o';
                else dot[25] = 'o';
                break;
            case 2:
                if (j == 0){
                    dot[1] = 'o'; dot[7] = 'o';
                }
                else if (j == 1){
                    dot[8] = 'o'; dot[14] = 'o';
                }
                else if (j == 2){
                    dot[15] = 'o'; dot[21] = 'o';
                }
                else{
                    dot[22] = 'o'; dot[28] = 'o';
                }
                break;
            case 3:
                if (j == 0){
                    dot[1] = 'o'; dot[4] = 'o'; dot[7] = 'o';
                }
                else if (j == 1){
                    dot[8] = 'o'; dot[11] = 'o'; dot[14] = 'o';
                }
                else if (j == 2){
                    dot[15] = 'o'; dot[18] = 'o'; dot[21] = 'o';
                }
                else{
                    dot[22] = 'o'; dot[25] = 'o'; dot[28] = 'o';
                }
                break;
            case 4:
                if (j == 0){
                    dot[1] = 'o'; dot[2] = 'o'; dot[6] = 'o'; dot[7]= 'o';
                }
                else if (j == 1){ dot[8] = 'o'; dot[9] = 'o'; dot[13] = 'o'; dot[14]= 'o';
                }
                else if (j == 2){ dot[15] = 'o'; dot[16] = 'o'; dot[20] = 'o'; dot[21]= 'o';
                }
                else{
                    dot[22] = 'o'; dot[23] = 'o'; dot[27] = 'o'; dot[28]= 'o';
                }
                break;
            case 5:
                if (j == 0){
                    dot[1] = 'o'; dot[2] = 'o';dot[4] = 'o';dot[6] = 'o'; dot[7] = 'o';
                }
                else if (j == 1){
                    dot[8] = 'o'; dot[9] = 'o'; dot[11] = 'o'; dot[13] = 'o'; dot[14] = 'o';
                }
                else if (j == 2){
                    dot[15] = 'o'; dot[16] = 'o'; dot[18] = 'o'; dot[20] = 'o'; dot[21] = 'o';
                }
                else {
                    dot[22] = 'o'; dot[23] = 'o'; dot[25] = 'o'; dot[27] = 'o'; dot[28] = 'o';
                }
                break;
            case 6:
                if (j == 0){
                    dot[1] = 'o'; dot[2] = 'o';dot[3] = 'o'; dot[5] = 'o';  dot[6] = 'o'; dot[7] = 'o';
                }
                else if (j == 1){
                    dot[8] = 'o'; dot[9] = 'o'; dot[10] = 'o'; dot[12] = 'o';  dot[13] = 'o'; dot[14] = 'o';
                }
                else if (j == 2){
                    dot[15] = 'o';dot[16] = 'o';dot[17] = 'o';  dot[19] = 'o';  dot[20] = 'o';  dot[21] = 'o';
                }
                else{
                    dot[22] = 'o'; dot[23] = 'o'; dot[24] = 'o'; dot[26] = 'o';  dot[27] = 'o';  dot[28] = 'o';
                }
                break;
        }
        out << "   " << values[j] << "\t";
    }
    return
    out << "\n+-----+\t" << "+-----+\t" << "+-----+\t" << "+-----+" << endl
        << "¦ " << dot[1] << " " << dot[2] << " ¦\t" << "¦ " << dot[8] <<" " << dot[9] << " ¦\t" << "¦ " << dot[15] <<" " << dot[16] << " ¦\t" << "¦ " << dot[22] <<" " << dot[23] << " ¦" << endl
        << "¦ " << dot[3] << dot[4] << dot[5] << " ¦\t" << "¦ " << dot[10] << dot[11] << dot[12] << " ¦\t" << "¦ " << dot[17] << dot[18] << dot[19] << " ¦\t" << "¦ " << dot[24] << dot[25] << dot[26] << " ¦" << endl
        << "¦ " << dot[6] << " " << dot[7] << " ¦\t" << "¦ " << dot[13] <<" " << dot[14] << " ¦\t" << "¦ " << dot[20] <<" " << dot[21] << " ¦\t" << "¦ " << dot[27] <<" " << dot[28] << " ¦" << endl
        << "+-----+\t" << "+-----+\t" << "+-----+\t" << "+-----+" << endl;

}

//-----------display rolled dice values, have user pair up, and return the pair totals-------------------
const int* CantStopDice::roll(){
    const char choices[5] = {'a','b','c', 'd'};     //user interface menu
    char in1;           //dice pair choice 1
    char in2;           //dice pair choice 2

    Dice::roll();
    cout << '\n'<< *this;
    pair_totals[0] = 0;
    pair_totals[1] = 0;

    for (int k = 0; k < this->nDice; ++k){
        cout << "   " << choices[k] << "\t";
        pair_totals[1] += values[k];
    }

    for (;;)
    {
        int first_total = 0;
        cout << "\nEnter two die choices to pair up FIRST (Higher Priority Pair): ";
        cin >> in1;
        cin >> in2;
        in1 = tolower(in1);
        in2 = tolower(in2);
        if (in1 == in2) {cout << "Cannot pair up the same dice! Try again.\n"; continue;}

        switch (in1){
            case 'a': first_total += values[0]; break;
            case 'b': first_total += values[1]; break;
            case 'c': first_total += values[2]; break;
            case 'd': first_total += values[3]; break;
            default: cout << "Invalid Input! Try again."; continue;
        }
        switch (in2){
            case 'a': first_total += values[0]; break;
            case 'b': first_total += values[1]; break;
            case 'c': first_total += values[2]; break;
            case 'd': first_total += values[3]; break;
            default: cout << "Invalid Input! Try again."; continue;
        }

        cout << "Higher priority pair = " << first_total << ". Lower priority pair = " << pair_totals[1] - first_total;
        cout << "\nEnter Y to confirm or N to re-do pair selection: ";
        cin >> in1;
        in1 = toupper(in1);
        if (in1 == 'Y' && cin.good())
        {
            pair_totals[0] = first_total;
            pair_totals[1] = pair_totals[1] - first_total;
            break;
        }
    }
    return pair_totals;
}

//-------------read dice values from file, pair up, then return pair totals----------------------
const int* FakeDice::roll(){
    if(fin.good())
    {
        fin >> values[0] >> values[1] >> values[2] >> values[3];
        pair_totals[0] = values[0] + values[1];
        pair_totals[1] = values[2] + values[3];

        if (fin.eof())
        {
            fatal("reached end of file!");
            return NULL;
        }
    }
    return pair_totals;
}


