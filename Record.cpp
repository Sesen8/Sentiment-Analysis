// Title: Lab 2 - Record.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>

#include "Record.h"

// Getter for _word member of Record class
// **Add your implementation of GetWord here
string Record::GetWord() const {
    return _word;
}


// Getter for _count member of Record class
// **Add your implementation of GetCount here
int Record::GetCount() const {
    return _count;
}


// Getter for _scoreTotal member of Record class
// **Add your implementation of GetScoreTotal here
int Record::GetScoreTotal() const {
    return _scoreTotal;
}


// Setter for _word member of Record class
// **Add your implementation of SetWord here
void Record::SetWord(string word) {
    _word = word;
}

// Setter for _count member of Record class
// **Add your implementation of SetCount here
void Record::SetCount(int count) {
    _count = count;
}


// Setter for _scoreTotal member of Record class
// **Add your implementation of SetScoreTotal here
void Record::SetScoreTotal(int scoreTotal) {
    _scoreTotal = scoreTotal;
}