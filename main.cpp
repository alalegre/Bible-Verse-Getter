#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include "helper.h"
#include "tools.h"

using json = nlohmann::json;
using namespace std;

int main(){
    // Opens and parses json file to be accessed and used
    ifstream webBibleStream("web.json");
    json bible = json::parse(webBibleStream);

    // Array of books to be used to check if book input exists in the bible
    string bibleBooks[] = {
    "Genesis", "Exodus", "Leviticus", "Numbers", "Deuteronomy",
    "Joshua", "Judges", "Ruth", "1 Samuel", "2 Samuel",
    "1 Kings", "2 Kings", "1 Chronicles", "2 Chronicles", "Ezra",
    "Nehemiah", "Esther", "Job", "Psalms", "Proverbs",
    "Ecclesiastes", "Song of Solomon", "Isaiah", "Jeremiah", "Lamentations",
    "Ezekiel", "Daniel", "Hosea", "Joel", "Amos",
    "Obadiah", "Jonah", "Micah", "Nahum", "Habakkuk",
    "Zephaniah", "Haggai", "Zechariah", "Malachi", "Matthew",
    "Mark", "Luke", "John", "Acts", "Romans",
    "1 Corinthians", "2 Corinthians", "Galatians", "Ephesians", "Philippians",
    "Colossians", "1 Thessalonians", "2 Thessalonians", "1 Timothy", "2 Timothy",
    "Titus", "Philemon", "Hebrews", "James", "1 Peter",
    "2 Peter", "1 John", "2 John", "3 John", "Jude",
    "Revelation"
    };

    // Array of existing tools for users to use
    string tools[] = {"vr", "ws"};

    string tool;
    string quit;
    cout << "\n--Bible Verse Retriever--" << endl;

    // Runs while input is not 'quit'
    while (quit != "quit"){
        cout << "\nType 'quit' to exit" << endl;
        cout << "Select a tool: Verse Retriever (vr), Word Search (ws)" << endl;
        getline(cin, tool);
        
        // Makes sure that capitalization and whitespace doesn't matter
        string mod = tool;
        mod.erase(remove_if(mod.begin(), mod.end(), ::isspace), mod.end());
        transform(mod.begin(), mod.end(), mod.begin(), ::tolower);
        quit = mod;

        // Checks for the existence of input tool and doesn't stop until input is valid
        int toolSize = sizeof(tools) / sizeof(tools[0]); 
        if (!toolExistence(tools, toolSize, tool) && quit != "quit"){
            cout << "Tool does not exist. Choose another existing tool." << endl;
            continue;
        }

        // Opens verse retriever tool
        else if (tool == "vr"){
            int bookLen = sizeof(bibleBooks) / sizeof(bibleBooks[0]);
            verseRetriever(bible, bibleBooks, bookLen);
            continue;
        }

        // Opens word search tool
        else if (tool == "ws"){
            wordSearch();
            continue;
        }
    }
}