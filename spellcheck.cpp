#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <time.h> 
using namespace std;

unordered_set<string> dictionary; //Creates an unordered set that contains strings

//Helper function declarations
void loadDictionary();

string parseWord(string input);


//Main function: Loads dictionary, selects mode, receives user inputs, checks word validity and score, and outputs
int main (){
    string inputWord, dummy1, word, lastWord = "", lastWord2 = "", parsedWord, fileName; 
    //InputWord: user input | dummy: used in loading of dictionary | lastWord lastWord2: storage for strings that came before string being checked atm. Initialize empty
    //parsedWord: word that has been uncapitalized and had punctuation removed | fileName: user input for files name
    clock_t start, current, progStart; //Two clock variables
    int wordCount = 0, errorCount = 0; 
    //wordCount: number of strings in doc | errorCount: number of errors found
    float clks_per_ms = CLOCKS_PER_SEC/1000, dictionaryLoad, fileLoad; //clks per ms value

    start = clock();
    progStart = clock();
    loadDictionary(); //Load dictionary into an unordered set
    dictionaryLoad = (float)(clock() - start)/clks_per_ms; //Done measuring
    cout << "Done Loading Dictionary in " << dictionaryLoad << " ms" << endl;

    //get user input for filename
    cout << "What file would you like to open?" << endl;
    cout << "Please ensure the file is in the same folder as this executable" << endl;
    cout << "Only .txt files are supported" << endl;
    cin >> fileName;

    start = clock(); //start timing
    ifstream input(fileName.c_str()); //load file into file stream (c_strt used to format name correctly)
    fileLoad = (clock() - start)/clks_per_ms; //stop timing
    cout << "Loaded file in " << fileLoad << " ms" << endl << endl;
    //Start timing
    start = clock();
    while(!input.eof()){ //Going until end of file stream
        if(wordCount-1) lastWord2 = lastWord; //storing word before last word (starting to record at 3rd word)
        if(wordCount) lastWord = word; //storing last word (starting to record at second word)
        input >> word; 
        parsedWord = parseWord(word); //parsing word
        if(parsedWord != ""){
            wordCount++; //only add to wordcount if word exists after parsing
            if(!dictionary.count(parsedWord) && parsedWord != ""){ //Only if parsed word is not empty, search set for word
                current = clock() - start; 
                errorCount++;
                //output error info        
                cout << "Word #" << wordCount << ": " << parsedWord << " not found in dictionary." << endl <<
                    "Word found here: " << lastWord2 << " " << lastWord << " " << word << endl <<
                    "This is error #" << errorCount << " found after " << current/clks_per_ms << "ms" << endl << endl;
            }
        }
    }
    current = clock() - start; //done timing
    double percent = 100-(100*((double)errorCount/(double)wordCount)); //calculating accuracy
    double wordTime = double(current/(clks_per_ms))/(double)wordCount; //calculating seconds per word
    double fileTime = double((clock()-progStart))/clks_per_ms; //calculating total file time
    //Output reports
    cout << "FINAL REPORT: found " << errorCount << " errors in " << wordCount << " words. This document had " << percent << " percent accuracy" << endl <<
    "PERFORMANCE REPORT" << endl << "  Spellcheck: " << current/clks_per_ms << "ms" << endl << "  Average time per word was " << wordTime << "ms" << endl <<
    "  Dictionary loaded in " << dictionaryLoad << "ms" << endl << "  File \"" << fileName.c_str() << "\" loaded in " << fileLoad << "ms" << endl <<
    "  Total Run time: " << fileTime << "ms" << endl;
    
}

//ParseWord: Takes in a string and outputs a formatted word
string parseWord(string input){
    string output = "", dummy, empty = "";
    //output: output string | dummy: used to temporarily store strings | empty: used as a return option if input word is not actual word (single punctuation)
    if(input.length() == 1 && ispunct(input[0])) return empty; //If input is a single punctuation piece, ignore it
    for(int i = 0; i < input.length(); i++){ //Looping through 
        if(!ispunct(input[i])){ //if not punctuation, concatenate to output string
            dummy = tolower(input[i]);
            output = output + dummy;
        }
        //This is a general catch for ' in words. It assumes that whenever an apostrophe is not at the start or end, it is meant to be there
        //Obviously, this is not 100% correct, but it will cover contractions like (can't, I'll, you've, carpenter's etc..) without needing a ton of checks.
        //If the punctuation is not a ' on the inside of the string, it will be ignored in the parsed word
        else if(input[i] == '\'' && i != input.length()-1 && i != 0){ 
            output = output + input[i];
        }
    }
    return output;
}

//LoadDictionary: loads dictionary from attached txt file
void loadDictionary(){
    ifstream dictionaryFile("Dictionary.txt");
    string dummy;
    cout << "Loading Dictionary" << endl;
    while(!dictionaryFile.eof()){ //inputting from file stream into dummy string and then dummy string into dictionary set
        dictionaryFile >> dummy; //Loops until eof reached
        dictionary.insert(dummy);
    }
}
