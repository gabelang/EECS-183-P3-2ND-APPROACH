/*
 * ciphers.cpp
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

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;


void ciphers() {
    string cipherChoice;
    string Caesar;
    string Vigenere;
    string Polybius;
    int key;
    string keyword;
    string encryptChoice;
    string message;
    string encrypted;
    string decrypted;

// ask user for cipher (Caesar, Vigenere, or Polybius)

    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    getline(cin, cipherChoice);
    cipherChoice = toUpperCase(cipherChoice);

    if (cipherChoice != "CAESAR" && cipherChoice != "C" && cipherChoice != "VIGENERE" && cipherChoice != "V" && cipherChoice != "POLYBIUS" && cipherChoice != "P") {
        cout << "Invalid cipher!" << endl;
    }

    cout << "Encrypt or decrypt: ";
    getline(cin, encryptChoice);
    encryptChoice = toUpperCase(encryptChoice);

    if (encryptChoice != "ENCRYPT" && encryptChoice != "E" && encryptChoice != "DECRYPT" && encryptChoice != "D") {
        cout << "Invalid mode!" << endl;
    }

    if ((cipherChoice == "CAESAR" || cipherChoice == "C") && (encryptChoice == "ENCRYPT" || encryptChoice == "E")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        cin >> key;
        encrypted = caesarCipher(message, key, true);
        cout << "The encrypted message is: " << encrypted << endl;
    }

    else if ((cipherChoice == "CAESAR" || cipherChoice == "C") && (encryptChoice == "DECRYPT" || encryptChoice == "D")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        cin >> key;
        decrypted = caesarCipher(message, key, false);
        cout << "The decrypted message is: " << decrypted << endl;
    }

    else if ((cipherChoice == "VIGENERE" || cipherChoice == "V") && (encryptChoice == "ENCRYPT" || encryptChoice == "E")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        encrypted = vigenereCipher(message, keyword, true);
        cout << "The encrypted message is: " << encrypted << endl;
    }
    else if ((cipherChoice == "VIGENERE" || cipherChoice == "V") && (encryptChoice == "DECRYPT" || encryptChoice == "D")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        decrypted = vigenereCipher(message, keyword, false);
        cout << "The decrypted message is: " << decrypted << endl;
    }

    else if ((cipherChoice == "POLYBIUS" || cipherChoice == "P") && (encryptChoice == "ENCRYPT" || encryptChoice == "E")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        char grid[SIZE][SIZE];
        encrypted = polybiusSquare(grid, keyword, message, true);
        cout << "The encrypted message is: " << encrypted << endl;
    }
    else if ((cipherChoice == "POLYBIUS" || cipherChoice == "P") && (encryptChoice == "DECRYPT" || encryptChoice == "D")) {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        char grid[SIZE][SIZE];
        decrypted = polybiusSquare(grid, keyword, message, false);
        cout << "The decrypted message is: " << decrypted << endl;
    }
}
/* void ciphers() {
    string cipherChoice;
    string Caesar;
    string Vigenere;
    string Polybius;
    int key;
    string keyword;
    string encryptChoice;
    string message;
    char grid[SIZE][SIZE];
    bool encrypt;
    string outputMessage;
    // ask user for cipher (Caesar, Vigenere, or Polybius)
    
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> cipherChoice;
    cipherChoice = toUpperCase(cipherChoice);
    if ((cipherChoice != "CAESAR" || cipherChoice != "C") &&
    (cipherChoice != "VIGENERE" || cipherChoice != "V") &&
    (cipherChoice != "POLYBIUS" || cipherChoice != "P")) {
        cout << "Invalid cipher!" << endl;
    }
    // ask user to encrypt or decrypt
    cout << "Encrypt or decrypt: ";;
    cin >> encryptChoice;
    encryptChoice = toUpperCase(encryptChoice);
    if (encryptChoice == "ENCRYPT" || encryptChoice == "E") {
        encrypt = true;
    }
    else if (encryptChoice == "DECRYPT" || encryptChoice == "D") {
        encrypt = false;
    }
    else {
        cout << "Invalid mode!" << endl;
    }
    // get message from user
    //cout << "Enter a message: ";
    //getline(cin, message);
    //cout << "What is your key: ";
    
    if (cipherChoice == "CAESAR" || cipherChoice == "C") {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        cin >> key;
        outputMessage = caesarCipher(message, key, encrypt);
        if (encrypt == true) {
            cout << "The encrypted message is: " << outputMessage;
        }
        else if (encrypt == false) {
            cout << "The decrypted message is: " << outputMessage;
        }
    }
    
    else if (cipherChoice == "VIGENERE" || cipherChoice == "V") {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        outputMessage = vigenereCipher(message, keyword, encrypt);
        if (encrypt == true) {
            cout << "The encrypted message is: " << outputMessage;
        }
        else if (encrypt == false) {
            cout << "The decrypted message is: " << outputMessage;
        }
    }
    
    else if (cipherChoice == "POLYBIUS" || cipherChoice == "P") {
        cout << "Enter a message: ";
        getline(cin, message);
        cout << "What is your key: ";
        getline(cin, keyword);
        outputMessage = polybiusSquare(grid, keyword, message, encrypt);
        if (encrypt == true) {
            cout << "The encrypted message is: " << outputMessage;
        }
        else if (encrypt == false) {
            cout << "The decrypted message is: " << outputMessage;
        }
    }
    
    //if ((cipherChoice == "CAESAR" || cipherChoice == "C") && (encrypt == true)) {
       // cout << "The encrypted message is: ";
    //}
        /*if (encryptChoice == "ENCRYPT" || encryptChoice == "E") {
            encrypt = true;
            if (encrypt == true) {
                string encrypted = caesarCipher(message, key, encrypt);
                cout << "The encrypted message is: " << encrypted;
            }
        }
        else if (encryptChoice == "DECRYPT" || encryptChoice == "D") {
            //cout << "Enter a message ";
            //getline(cin, message);
            //cout << "What is your key: ";
            //cin >> key;
            encrypt = false;
            if (encrypt == false) {
                string decrypted = caesarCipher(message, key, false);
                cout << "The decrypted message is: " << decrypted;
            }
        }
        
         else {
            cout << "Invalide mode!" << endl;
        }
    }
    
    
    
    
    
    
    
    else if (cipherChoice == Vigenere) {

        if (encryptChoice == "Encrypt") {
            cout << "Enter a message: ";
            getline(cin, message);
            cout << "What is your key: ";
            getline(cin, keyword);
            string encrypted = vigenereCipher(message, keyword, true); //(no matching function call error for this one and below)
            cout << "The encrypted message is: " << encrypted;
        }
        else if (encryptChoice == "decrypt") {
            cout << "Enter a message: ";
            getline(cin, message);
            cout << "What is your key: ";
            getline(cin, keyword);
            string decrypted = vigenereCipher(message, keyword, false);
            cout << "The decrypted message is: " << decrypted;
        }
        else {
            cout << "Invalid mode!" << endl;
        }
    }
    
    else if (cipherChoice == Polybius) {
        if (encryptChoice == "Encrypt") {
            cout << "Enter a message: ";
            getline (cin, message);
            cout << "What is your key: ";
            getline(cin, keyword);
            string encrypted = polybiusSquare(grid, keyword, message, true); //(not sure what to put in [])
            cout << "The encrypted message is: " << encrypted;
        }
        else if (encryptChoice == "decrypt") {
            cout << "Enter a message: ";
            getline(cin, message);
            cout << "What is your key: ";
            getline(cin, keyword);
            string decrypted = polybiusSquare(grid, keyword, message, false);
            cout << "The decrypted message is: " << decrypted;
        }
        else {
            cout << "Invalid mode!" << endl;
        }
    }

    
    // get key or keyword from user
    
    // encrypt or decrypt message using selected cipher and key(word)
    
    // print encrypted/decrypted message
    
    //cout << "The encrypted message is: ";
    
    //return; */
// }

