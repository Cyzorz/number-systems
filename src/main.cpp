#include <iostream>
#include <string>
#include <regex>
#include "functions.h"
using namespace std;

int main() {
    int binaryNumber = 0;
    int hexadecimalNumber = 0;
    int octalNumber = 0;
    int inputTwo = 0;
    string inputOne = "";
    int inputThree = 0;
    bool isBinary = false;
    bool isHex = false;
    bool isOctal = false;

    while (true) {
        cout << "\nPlease enter your number:\n\n--> ";
        cin >> inputOne;
        cout << "\nHow would you like me to check your number system?\n1) Guess\n2) Exit\n\n--> ";
        cin >> inputTwo;

        char* char_array = const_cast<char*>(inputOne.c_str());
        int octalDecimal = octalToDecimal(stoi(inputOne));
        int binaryDecimal = binaryToDecimal(stoi(inputOne));

        switch (inputTwo) {
        case 1:
            if (regex_match(inputOne, regex("^[0-1]+$")) == true) {
                cout << "\nThis looks like a Binary Number!" << endl;
                isBinary = true;
            } else if (regex_match(inputOne, regex("^[0-7]+$")) == true) {
                cout << "\nThis looks like a Octal!" << endl;
                isOctal = true;
            }
            else if (regex_match(inputOne, regex("^[0-9A-Fa-f]+$")) == true) {
                cout << "\nThis looks like a Hexadecimal!" << endl;
                isHex = true;             
            }
            break;
        case 2:
            cout << "Are you sure?\n1) Yes\n2) No\n\n--> ";
            cin >> inputThree;

            switch (inputThree) {
            case 1:
                return 0;
                break;
            case 2:
                break;
            default:
                cout << "Please specify a valid number!\n";
                break;
            }
            break;
        default:
            cout << "Please specify a valid number!\n";
            break;
        }

        if (isHex == true) {
            cout << "\nThe output for the Hexadecimal " << inputOne << " is:\n" << "As a Decimal: " << hexToDecimal(char_array) << endl << "As a Binary Number: ";
            decimalToBinary(hexToDecimal(char_array));
            cout << endl << "As an Octal: ";
            decimalToOctal(hexToDecimal(char_array));
            cout << endl;
            return 0;
        }
        else if (isOctal == true) {
            cout << "\nThe output for the Octal " << inputOne << " is:\n" << "As a Decimal: " << octalDecimal << endl << "As a Hex: " << hex << octalDecimal << endl << "As a Binary Number: ";
            decimalToBinary(octalDecimal);
            cout << endl;
            return 0;
        }
        else if (isBinary == true) {
            cout << "\nThe output for the Binary number " << inputOne << " is:\n" << "As a Decimal: " << binaryDecimal << endl << "As a Hex: " << hex << binaryDecimal << endl << "As an Octal: ";
            decimalToOctal(hexToDecimal(char_array));
            cout << endl;
            return 0;
        }
    }


    return 0;
}