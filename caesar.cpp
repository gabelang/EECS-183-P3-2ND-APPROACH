/*
 * caesar.cpp
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

#include "caesar.h"
#include <iostream>

using namespace std;


char shiftAlphaCharacter(char c, int n) {
    int temp = 0;
    if (c >= 'a' && c <= 'z') {
        temp = c;
        temp = temp + n % 26;
        while (temp > 122) {
            temp = temp - 26;
        }
       while (temp < 97) {
            temp = temp + 26;
        }
        c = temp;
    }
    else if (c >= 'A' && c <= 'Z') {
        temp = c;
        temp = temp + n % 26;
        while (temp > 90) {
            temp = temp - 26;
        }
       while (temp < 65) {
            temp = temp + 26;
        }
        c = temp;
    }
    else {
        return c;
    }
    return c;
}

string caesarCipher(string original, int key, bool encrypt) {
    if (encrypt == true) {
        for (int i = 0; i < original.length(); i++) {
            char c = original[i];
            original[i] = shiftAlphaCharacter(c, key);

            }
        }
    else if (encrypt == false) {
        key = key * (-1);
        for (int i = 0; i < original.length(); i++) {
            char c = original[i];
            original[i] = shiftAlphaCharacter(c, key);
        }
    }
    return original;
}



