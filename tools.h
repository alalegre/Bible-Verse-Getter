#ifndef VERSERET_H
#define VERSERET_H

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "helper.h"

void verseRetriever(json bible, string bibleBooks[], int bookLen);
void wordSearch();

#endif