#ifndef HELPER_H
#define HELPER_H

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

bool bookExistence(const string bibleBooks[], int size, const string book);
bool toolExistence(const string tools[], int size, const string tool);
int maxChapter(json bible, int arrayLen, string book);
int maxVerse(json bible, int arrayLen, string book, int chapter);
string getVerse(json bible, int arrayLen, string book, unsigned int chapter, unsigned int verse);





#endif