#include <iostream>
#include <string>
using namespace std;

int hexToDecimal(char input[]) {
    int hexBase = 1;
    int hexValue = 0;

    for (int x = strlen(input) - 1; x >= 0; x--) {
        if (input[x] >= '0' && input[x] <= '9') {
            hexValue += (input[x] - 48) * hexBase;
            hexBase *= 16;
        }
        else if (input[x] >= 'A' && input[x] <= 'F') {
            hexValue += (input[x] - 55) * hexBase;
            hexBase *= 16;
        }
    }
    return hexValue;
}

int binaryToDecimal(int input) {
    int binaryBase = 1;
    int binaryValue = 0;

    while (input) {

        int prior_integer = input % 10;

        input /= 10;
        binaryValue += prior_integer * binaryBase;
        binaryBase *= 2;
    }
    return binaryValue;
}

int octalToDecimal(int input) {
    int binaryBase = 1;
    int binaryValue = 0;

    while (input) {

        int prior_integer = input % 10;

        input /= 10;
        binaryValue += prior_integer * binaryBase;
        binaryBase *= 8;
    }
    return binaryValue;
}

void decimalToBinary(int input) {
    int binaryValue[32];
    int x = 0;

    while (input) {
        binaryValue[x] = input % 2;
        input /= 2;
        x++;
    }

    for (int y = x - 1; y >= 0; y--) {
        cout << binaryValue[y];
    }

}

void decimalToOctal(int input) {
    int octalValue[100];
    int x = 0;
    while (input != 0) {
        octalValue[x] = input % 8;
        input /= 8;
        x++;
    }

    for (int y = x - 1; y >= 0; y--) {
        cout << octalValue[y];
    }
}