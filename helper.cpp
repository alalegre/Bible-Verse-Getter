#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "helper.h"

using json = nlohmann::json;
using namespace std;

// Checks for the book's existence in the bible
bool bookExistence(const string bibleBooks[], int size, const string book){
    return find(bibleBooks, bibleBooks + size, book) != bibleBooks + size;
}

// Checks for the existence of the tool within the tools array
bool toolExistence(const string tools[], int size, const string tool){
    return find(tools, tools + size, tool) != tools + size;
}

// Finds the max number of chapter within a book
int maxChapter(json bible, int arrayLen, string book){
    // Print out how many chapters are in the chosen book
    int maxChap;
    for (int i = 0; i < arrayLen; i++){
        json currVerse = bible["verses"][i];
        if (currVerse["book_name"] == book){
            maxChap = currVerse["chapter"];
        }
        else {
            continue;
        }
    }
    return maxChap;
}

// Finds the max number of verse within the book's chapter
int maxVerse(json bible, int arrayLen, string book, int chapter){
    int maxVer;
    for (int i = 0; i < arrayLen; i++){
        json currVerse = bible["verses"][i];
        if (currVerse["book_name"] == book){
            if (currVerse["chapter"] == chapter){
                maxVer = currVerse["verse"];
            }
        }
        else {
            continue;
        }
    }
    return maxVer;
}

// Retrieves the verse based on book name, chapter and verse number
string getVerse(json bible, int arrayLen, string book, unsigned int chapter, unsigned int verse){
    for (int i = 0; i < arrayLen; i++){
        json currVerse = bible["verses"][i];
        if (currVerse["book_name"] == book){
            if (currVerse["chapter"] == chapter){
                if (currVerse["verse"] == verse){
                    return currVerse["text"];
                }
            }
        }
    }
    return "Verse not found.";
}