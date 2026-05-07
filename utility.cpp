/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Gabriel Lang and Alex DiGennaro
 * <#Uniqnames#>
 *
 * EECS 183: Project 3
 * Winter 2022
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>


string toUpperCase(string original) {
    // TODO: implement
    
    for(int i = 0; i < original.length(); i++) {
    original[i] = toupper(original[i]);
    }
    
    // returning a string to avoid compile error
    return original;
}

string removeNonAlphas(string original) {
    // TODO: implement
    
    string newString;
    for (int i = 0; i < original.length(); i++) {
        if ((original[i] >= 'a' && original[i] <= 'z') || (original[i] >= 'A'
                                                && original[i] <= 'Z')) {
            newString += original[i];
        }
    }
    
    // returning a string to avoid compile error
    return newString;
}

string removeDuplicate(string original) {
    // TODO: implement
    
    int i;
    int j;
    string modified = "";
    for (i = 0; i < original.size(); i++) {
        for (j = 0; j < original.size(); j++) {
            if (original[i] == original[j]) {
                break;
            }
        }
        if (i == j) {
            modified += original[i];
        }
    }
    // cout << modified;
    // returning a string to avoid compile error
    return modified;
}

int charToInt(char original) {
    // TODO: implement
    /* int temp = 0;
    for (int i = 0; i <= 9; i++) {
        temp = original % 10;
        // temp = original;
        */
    // int temp = 0;
    // string hold;
    /* for (int i = 0; i <= 9; i++) {
        temp = int(original);
        temp = hold[original];
        count = 9;
    } */
    // while (temp < 10) {
        // temp = original;
    // }
    // original = temp;
    // int value = original;
    // int temp = original;
    //return hold[original];
    /* const int size = 10;
    int temp[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < size; i++) {
        original = i;
        original = temp[i];
    }
    return original; */
    int a;
    for (int i = 0; i != original; ++i) {
        
        if (i + 1 == original) {
            a = i + 1;
        }
    }
    return a - 48;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
