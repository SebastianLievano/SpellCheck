#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <time.h> 
using namespace std;

unordered_set<string> dictionary; //Creates an unordered set that contains strings


void loadDictionary();

string parseWord(string input);


// PrintFunction can be used to print entire dictionary


//Main function: Loads dictionary, selects mode, receives user inputs, checks word validity and score, and outputs
int main (){
    string inputWord, dummy1, nextWord, word, lastWord = "", lastWord2 = "", parsedWord; //InputWord: userInput, dummy: used in loading of dictionary, finalWord: processed word
    clock_t start, current;
    int userInput, wordCount = 0, errorCount = 0; //Factor: multiplication factor of word score, userInput: used in startup meno
    float clks_per_ms = CLOCKS_PER_SEC/1000;
    bool keepGoing = true; //scrabbleMode: if scrabble mode is used or not, keepGoing: toggled off when user wishes to exit program

    loadDictionary();

    start = clock();
    ifstream input("input.txt");
    current = clock() - start;
    cout << "Loaded file in " << current/clks_per_ms << " ms" << endl << endl;
    start = clock();
    while(!input.eof()){
        if(wordCount-1) lastWord2 = lastWord;
        if(wordCount) lastWord = word;
        wordCount++;
        input >> word;
        parsedWord = parseWord(word);
        if(!dictionary.count(parsedWord) && parsedWord != ""){
            current = clock() - start;
            errorCount++;        
            cout << "Word #" << wordCount << ": " << parsedWord << " not found in dictionary." << endl <<
                "Word found here: " << lastWord2 << " " << lastWord << " " << word << endl <<
                "This is error #" << errorCount << " found after " << current/clks_per_ms << "ms" << endl << endl;
        }
    }
    current = clock() - start;
    double percent = 100-(100*((double)errorCount/(double)wordCount));
    double wordTime = double(current/(clks_per_ms))/(double)wordCount;
    cout << "FINAL REPORT: found " << errorCount << " errors in " << wordCount << " words. This document had " << percent << " percent accuracy" << endl <<
    "PERFORMANCE REPORT: Spellcheck took " << current/clks_per_ms << "ms total. Average time per word was " << wordTime << "ms" << endl;
}

string parseWord(string input){
    string output, dummy, empty = "";
    if(input.length() == 1 && ispunct(input[0])) return empty;
    if(!ispunct(input[0])) output = tolower(input[0]);
    for(int i = 1; i < input.length(); i++){
        if(!ispunct(input[i])){
            dummy = tolower(input[i]);
            output = output + dummy;
        }
        else if(input[i] == '\''){
            output = output + input[i];
        }
    }
    return output;
}

void printSet(unordered_set<string> const &dict)
{
    for (auto it = dict.cbegin(); it != dict.cend(); it++) { //iterator iterates until it reaches end of set. 
        cout << *it << ' ' << endl; //prints whatever iterator is pointing at
    }
}

bool spellCheck(string word){
    if(dictionary.count(word)){
        return true;
    }
    else return false;
}

void loadDictionary(){
    clock_t t;
    ifstream dictionaryFile("Dictionary.txt");
    float clks_per_ms = CLOCKS_PER_SEC/1000;
    string dummy;
    cout << "Loading Dictionary" << endl;
    t = clock(); //start measuring time here
    while(!dictionaryFile.eof()){ //inputting from file stream into dummy string and then dummy string into dictionary set
        dictionaryFile >> dummy; //Loops until eof reached
        dictionary.insert(dummy);
    }
    t = clock() - t; //Done measuring
    cout << "Done Loading Dictionary in " << t/clks_per_ms << " ms" << endl;
}
