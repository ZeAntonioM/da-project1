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

/**
 * @brief Draws an header 
 * 
 * @param size title for header
 * @param title size of the header
 * @return string String to be 1printed
 * @complexity O(1)
 */
string drawHeader(int size, string title);

/**
 * @brief Draws Footer
 * 
 * @param size 
 * @return string String to be printed
 * @complexity O(1)
 */
string drawFooter(int size);

/**
 * @brief Draws a number i of fields with a title inside
 * 
 * @param fields Title and space for field
 * @param i number of fields
 * @return string String to be printed
 * @complexity O(n)
 */
string drawFields(vector<pair<string, int>> fields, int i);

/**
 * @brief Draws line
 * 
 * @param size Size of the line
 * @return string String to be printed
 */
string drawLine(int size);

/**
 * @brief Draws Sub-Header
 * 
 * @param size Size of Subheader
 * @param title Title of SubHeader
 * @return string String to be printed
 */
string drawSubHeader(int size, string title);


#endif //DA_PROJECT1_DRAWUTILS_H
