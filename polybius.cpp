/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * <#description#>
 */


#include "polybius.h"
#include <string>
#include <iostream>
using namespace std;


string mixKey(string key) {
    string y = key + ALNUM;
    string x = removeDuplicate(y);
    return x;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int i = 0;
    if (content.length() == 36) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                grid[row][col] = content.at(i);
                i += 1;
            }
        }
    }
   else if (content.length() != 36) {
       cout << "Invalid Message!" << endl;
   }
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    string temp1;
    string temp2;
    int row;
    int col;
    int tempRow;
    int tempCol;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (c == grid[row][col]) {
                tempRow = row;
                tempCol = col;
                temp1 = to_string(tempRow);
                temp2 = to_string(tempCol);
                return temp1 + temp2;
            }
        }
    }
    return temp1 + temp2;
}

string polybiusSquare(char grid[SIZE][SIZE], string key, string original, bool encrypt) {
    string newKey = toUpperCase(key);
    newKey = removeDuplicate(newKey);
    string newOriginal = toUpperCase(original);
    string encrypted = "";
    //int positionNewOriginal = 0;
    if (encrypt == true) {
        newKey = mixKey(newKey);
        fillGrid(grid, newKey);
        for (int i = 0; i < newOriginal.length(); i++) {
            if (newOriginal[i] == ' ') {
                encrypted = encrypted + " ";
            }
            else {
            encrypted = encrypted + findInGrid(newOriginal[i], grid);
            // newOriginal[i] = charToInt(newOriginal[i]);
            }
            
        }
        
        // printGrid(grid);
        return encrypted;
    }
    else if (encrypt == false) {
        // key = -1 * mixKey(key);
        newKey = mixKey(newKey);
        fillGrid(grid, newKey);
        //char encrypted[1 + 1];
        for (int j = 0; j < original.length(); j++) {
            // char c = original[i];
            if (newOriginal[j] == ' ') {
                encrypted = encrypted + " ";
            }
            else {
                encrypted[j] = encrypted[j + 1];
                encrypted = encrypted + findInGrid(newOriginal[j], grid);
            // encrypted = charToInt(encrypted[j]);
            
            }
        }
    }
    return newOriginal;
}
