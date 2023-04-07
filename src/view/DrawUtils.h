//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_DRAWUTILS_H
#define DA_PROJECT1_DRAWUTILS_H
#include "iostream"
#include "string"
using namespace std;
/**
     * @brief checks an word for the number of special characters it has
     * @param word word to be checked for special characters
     * @return the number of special characters in the word
     * @complexity O(c) being c the length of the word
     */
int specialChars(string word);

string drawHeader(int size, string title);

string drawFooter(int size);
string drawFields(vector<pair<string,int>> fields,int i);
string  drawLine(int size);
string drawSubHeader(int size,string title);
#endif //DA_PROJECT1_DRAWUTILS_H
