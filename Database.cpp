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

// **Add your implementations for InitDatabase, AddWordToDatabase, FindWordInDatabase, and GetInfoAboutDatabase
// **The parameter "records" is an array of Record objects.  Each Record stores information about one word.
// **The parameter "size" records the current number of slots in the array which are filled.
// **The parameter "capacity" specifies the maximum number of slots in the array.  If you were to
// **call AddWordToDatabase with a new word, and the current value of "size" was equal to "capacity" the
// **the function would not do the insertion and return false instead of true.

// This function sets the number of words stored in the database to zero to make space for the next file.
// Parameters:
//      capacity -- the maximum number of slots in the array
//      records -- array of Record objects. Each Record stores information about one word
//      size -- the current number of slots in the array which are filled
//
// Returns:
//      nothing
// Possible Errors:
//      **<describe possible errors>
void InitDatabase(int capacity, Record records[], int& size){
    size = 0;

}

// **Don't forget to add header comments before each function using the following format:
// **<Describe what this function does
// Parameters:
//      capacity -- the maximum number of slots in the array
//      records -- array of Record objects. Each Record stores information about one word
//      size -- the current number of slots in the array which are filled
//      ...
// Returns:
//      true -- if
// Possible Errors:
//      **<describe possible errors>
//
bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score){
    cout << "AddWordToDatabase " << "\"" << word << "\"" << " Score: " << score << endl;


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
//      word --
//      occurrences --
//      averageScore --
//      ...
// Returns:
//      nothing
// Possible Errors:
//      **<describe possible errors>
//
void FindWordInDatabase(const Record records[], int size, const string& word, int& occurrences, double& averageScore){

    for (int i =0; i<size; ++i) {
        Record newRecordWord = records[i];

        if (newRecordWord.GetWord() == word){
            occurrences = newRecordWord.GetCount();
            averageScore = newRecordWord.GetScoreTotal();
            break;

        }
        else {
            occurrences = 0;
            averageScore = NEUTRAL;
        }


    }


}

// **Don't forget to add header comments before each function using the following format:
// **<Describe what this function does
// Parameters:
//      **<parameter name> -- <description of parameter>
//      **<parameter name> -- <description of parameter>
//      **<parameter name> -- <description of parameter>
//      ...
// Returns:
//      **<describe meaning of return value or put "nothing" if this is a function declared void>
// Possible Errors:
//      **<describe possible errors>
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

        if (average > maxScore){
            maxScore = average;
        }
        if(average < minScore){
            minScore = average;
        }

        if (occurrences > maxOccurrences){
            maxOccurrences = occurrences;
        }
        if (occurrences < minOccurrences){
            minOccurrences = occurrences;
        }


    }
}

