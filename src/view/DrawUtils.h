//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_DRAWUTILS_H
#define DA_PROJECT1_DRAWUTILS_H
#include "iostream"
#include "string"
using namespace std;

int specialChars_(string word);

string drawHeader(int size, string title);

string drawFooter(int size);
string drawFields(vector<pair<string,int>> fields,int i);
string  drawLine(int size);
#endif //DA_PROJECT1_DRAWUTILS_H
