//
//  test.cpp
//  EECS-183-Project3
//
//  Created by Gabe Lang on 2/18/22.
//
#include <iostream>
#include <stdio.h>
#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
// #include "ciphers.cpp"
//#include "start.cpp"

using namespace std;

void testShiftAlphaCharacter();
void testRemoveNonAlphas();
void testCaesarCipher();
void testToUpperCase();
void testCharToInt();
void testCiphers();
void testRemoveDuplicate();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testShiftAlphaCharacter();
    testRemoveNonAlphas();
    // Repeat for all other functions to be tested
    testCaesarCipher();
    testToUpperCase();
    testCharToInt();
    testCiphers();
    testRemoveDuplicate();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    // continue tests
    cout << shiftAlphaCharacter('a', 0) << endl;
    cout << shiftAlphaCharacter('b', 2) << endl;
    cout << shiftAlphaCharacter('X', 5) << endl;
    cout << shiftAlphaCharacter('X', 50) << endl;
    cout << shiftAlphaCharacter('Z', 3) << endl;
    
    return;
}

void testRemoveNonAlphas() {
    cout << "Now testing function RemoveNonAlphas" << endl;
    cout << removeNonAlphas("Hello!") << endl;
    cout << removeNonAlphas("EECS-183!") << endl;
    cout << endl;
    return;
}

void testCaesarCipher() {
    cout << caesarCipher("We are Victors!", 1, true) << endl;
    cout << caesarCipher("Meet me at Joe's at midnight", 1, true) << endl;
    cout << caesarCipher("This is a secret - tell nobody!", 7, true) << endl;
    cout << caesarCipher("Dogs are awesome!", 9, true) << endl;
    cout << caesarCipher("This will encrypt", 3, false) << endl;
    cout << caesarCipher("I'm hungry!", 4, false) << endl;
    cout << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    cout << endl;
    return;
}

void testToUpperCase() {
    cout << toUpperCase("forty") << endl;
    cout << toUpperCase("") << endl;
    cout << toUpperCase("let's go to the arb!") << endl;
    cout << endl;
    return;
}

void testCharToInt() {
    cout << charToInt('0') << endl;
    cout << charToInt('1') << endl;
    cout << charToInt('2') << endl;
    cout << charToInt('3') << endl;
    cout << charToInt('4') << endl;
    cout << charToInt('5') << endl;
    cout << charToInt('6') << endl;
    cout << charToInt('7') << endl;
    cout << charToInt('8') << endl;
    cout << charToInt('9') << endl;
    //cout << charToInt('p') << endl;
    //cout << charToInt(' ') << endl;
    //cout << charToInt('7') << endl;
    //cout << charToInt('l') << endl;
    cout << endl;
    return;
}

void testCiphers() {
    // cout << ciphers() << endl;
    
}

void testRemoveDuplicate() {
    cout << removeDuplicate("hello") << endl;
    cout << removeDuplicate("Apple") << endl;
    cout << removeDuplicate("racecar") << endl;
    cout << removeDuplicate("hello professor!") << endl;
    cout << endl;
    return;
}

void testVigenereCipher() {
    cout << vigenereCipher("We are Victors!", "apple", true) << endl;
    cout << vigenereCipher("Meet me at Joe's at midnight", "Blue", true) <<
    endl;
    cout << vigenereCipher("This is a secret - tell nobody!", "Michigan", true
                            ) << endl;
    cout << vigenereCipher("Dogs are awesome!", "Wolverine", true) << endl;
    cout << vigenereCipher("This will encrypt", "victors", false) << endl;
    cout << vigenereCipher("I'm hungry!", "Vigenere", false) << endl;
    cout << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << endl;
    cout << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << endl;
    cout << endl;
    return;
}

void testFillGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    printGrid(grid);
    // fillGrid(grid, "APPLE");
    // printGrid(grid);
    // fillGrid(grid, "WOLVERINES");
   //  printGrid(grid);
}

void testMixKey() {
cout << mixKey("POLYBIUS") << endl;
cout << mixKey("forever") << endl;
cout << mixKey("call") << endl;
cout << mixKey("") << endl;
}

void testFindInGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << findInGrid('A', grid) << endl;
    cout << findInGrid('B', grid) << endl;
    cout << findInGrid('C', grid) << endl;
    cout << findInGrid('G', grid) << endl;
    cout << findInGrid('9', grid) << endl;
}

void testPolybiusSquare() {
    char grid[SIZE][SIZE];
    cout << polybiusSquare(grid, "Apple", "Wolverines", true) << endl;
    cout << polybiusSquare(grid, "Potato", "Victors", true) << endl;
    cout << polybiusSquare(grid, "Squirrel", "Dogs rule", true) << endl;
    cout << polybiusSquare(grid, "EECS", "Project 3", true) << endl;
    cout << polybiusSquare(grid, "EECS", "14302000 04021005", false) << endl;
}
