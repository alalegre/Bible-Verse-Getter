#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "helper.h"
#include "tools.h"

using json = nlohmann::json;
using namespace std;

// Tool to retrieve verse based on user input
void verseRetriever(json bible, string bibleBooks[], int bookLen){
    string book;
    unsigned int chapter;
    unsigned int verse;
    int arrayLen = bible["verses"].size(); // Used for looping

    cout << "Enter a book (Capitalize the name): ";

    // Input can include whitespace between number and name, although it has to match the book name
    getline(cin, book);

    string quit;
    string mod = book;
    mod.erase(remove_if(mod.begin(), mod.end(), ::isspace), mod.end());
    transform(mod.begin(), mod.end(), mod.begin(), ::tolower);
    quit = mod;

    // Exits program if input is 'quit'
    if (quit == "quit"){
        exit(1);
    }

    // Checks if the book exist and loops while input is invalid
    while (!bookExistence(bibleBooks, bookLen, book) && quit != "quit"){
        cout << "Book does not exist in the bible. Choose another book: ";
        // cin.clear(); // Clears input buffer
        getline(cin, book);

        // Removes whitespace and turns input to lowercase to check if it's the word 'quit'
        mod = book;
        mod.erase(remove_if(mod.begin(), mod.end(), ::isspace), mod.end());
        transform(mod.begin(), mod.end(), mod.begin(), ::tolower);
        quit = mod;

        // Breaks out of loop if book input exists in the bible
        if (bookExistence(bibleBooks, bookLen, book)){
            break;
        }

        // Exits program
        else if (quit == "quit"){
            exit(1);
        }
    }
    
    // Print out how many chapters are in the chosen book
    int maxChap = maxChapter(bible, arrayLen, book);
    cout << "Enter chapter number " << "(1 - " << maxChap << "): ";
    cin >> chapter;
    
    // Checks for input validity
    while (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid. Numbers only." << endl;
        cout << "Choose a chapter within 1 - " << maxChap << ": ";
        cin >> chapter;
    }

    // Checks if input is within bounds
    while (chapter < 1 || int(chapter) > maxChap){
        if (chapter < 1 || int(chapter) > maxChap){
            cout << "Invalid chapter number. Choose a chapter within 1 - " << maxChap << ": ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear(); // Clears input buffer
            cin >> chapter;
        }
        // Breaks out of loop if input is within bounds
        if (chapter >= 1 && int(chapter) <= maxChap){
            break;
        }
    }
    
    // Print out how many verses are in the chosen chapter
    int maxVer = maxVerse(bible, arrayLen, book, chapter);
    
    cout << "Enter verse number " << "(1 - " << maxVer << "): ";
    cin >> verse;
    
    // Checks for input validity
    while (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid. Numbers only." << endl;
        cout << "Choose a verse within 1 - " << maxVer << ": ";
        cin >> verse;
    }

    // Checks if input is within bounds
    while (verse < 1 || int(verse) > maxVer){
        cout << "Invalid verse number. Choose a verse within 1 - " << maxVer << ": ";
        cin.clear(); // Clears input buffer
        cin >> verse;

        // Breaks out of loop if input is within bounds
        if (verse >= 1 && int(verse) <= maxVer){
            break;
        }
    }

    // Prints 'book chapter:verse' and the verse
    string chosenVerse = getVerse(bible, arrayLen, book, chapter, verse);
    cout << "\n" << book << " " << chapter << ":" << verse << endl;
    cout << chosenVerse << endl;

    cin.clear(); // Clears input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores leftover input
}

// Tool to retrieve every verse with the input word
void wordSearch(){
    cout << "Not yet implemented!" << endl;
}