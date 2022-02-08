// Title: Lab 2 - Database.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>

#include "Database.h"
#include "Record.h"
#include <iostream>
#include <fstream>

using namespace std;
using std::cout;

// This is the value used to score a word not found in the database
const double NEUTRAL = 2.0;


// This function sets the number of words stored in the database to zero to make space for the next file.
// Parameters:
//      capacity -- the maximum number of slots in the array
//      records -- array of Record objects. Each Record stores information about one word
//      size -- the current number of slots in the array which are filled
//
// Returns:
//      nothing
// Possible Errors:
//      nothing
void InitDatabase(int capacity, Record records[], int& size){
    size = 0;

}

// This function iterates through the records array an adds the words found in BuildDataBase to the database.
// Parameters:
//      capacity -- the maximum number of slots in the array
//      records -- array of Record objects. Each Record stores information about one word
//      size -- the current number of slots in the array which are filled
//      ...
// Returns:
//      true -- if word is found in database
// Possible Errors:
//      might add duplicates
//
bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score){

    for (int i =0; i<size; ++i) {
         Record newRecordWord = records[i];

         if (newRecordWord.GetWord() == word){
             newRecordWord.SetCount(newRecordWord.GetCount() +1);
             newRecordWord.SetScoreTotal(newRecordWord.GetScoreTotal()+score);
             records[i] = newRecordWord;
             return true;
         }
     }

    Record* newRec = new Record();
    newRec ->SetWord(word);
    newRec ->SetCount(1);
    newRec ->SetScoreTotal(score);
    records[size] = *newRec;


    size += 1;

    return true;
}

// **Don't forget to add header comments before each function using the following format:
// **<Describe what this function does
// Parameters:
//      records -- array of Record objects. Each Record stores information about one word
//      size -- the current number of slots in the array which are filled
//      word -- the word found in the string
//      occurrences -- number of times the word shows up
//      averageScore -- average of the scores sent in
//      ...
// Returns:
//      nothing
// Possible Errors:
//      might not work with empty file
//
void FindWordInDatabase(const Record records[], int size, const string& word, int& occurrences, double& averageScore){
    for (int i =0; i<size; ++i) {
        Record newRecordWord = records[i];

        if (newRecordWord.GetWord() == word){
            occurrences = newRecordWord.GetCount();
            averageScore = newRecordWord.GetScoreTotal();
            break;

        }
        else if (newRecordWord.GetWord() != word){
            occurrences = 0;
            averageScore = NEUTRAL;
        }
    }
}

// This function calculates the maximum, and minimum of the scores and the scores occurrences.
// Parameters:
//      records -- array of Record objects. Each Record stores information about one word
//      size -- the current number of slots in the array which are filled
//      numberWord -- the amount of words in file
//      maxOccurrences -- maximum times a score shows up
//      minOccurrences -- minimum times a score shows up
//      maxScore -- maximum score found
//      minScore -- minimum score found
// Returns:
//      nothing
// Possible Errors:
//      might not find the right max and min if file is short.
//
void GetInfoAboutDatabase(const Record records[], int size,
                          int& numberWords, int& maxOccurrences, int& minOccurrences, double& maxScore, double& minScore){

    maxScore = 0;
    minScore = INT32_MAX;
    numberWords = size;
    maxOccurrences = 0;
    minOccurrences = INT32_MAX;

    for (int i =0; i<size; ++i) {
        Record newRecordWord = records[i];
        int scores = newRecordWord.GetScoreTotal();
        double occurrences = newRecordWord.GetCount();
        double average = scores/occurrences;

        if (occurrences > maxOccurrences){
            maxOccurrences = occurrences;
        }
        if (occurrences < minOccurrences){
            minOccurrences = occurrences;
        }

        if (average > maxScore){
            maxScore = average;
        }
        if(average < minScore){
            minScore = average;
        }
    }
}

