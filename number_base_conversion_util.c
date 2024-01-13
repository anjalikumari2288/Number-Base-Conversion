#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert a decimal number to a string in the specified base
void convertToBase(long long decimalNumber, int outputBase, char *result) {
    char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Handle special case when the decimal number is 0
    if (decimalNumber == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    // Initialize variables
    int index = 0;
    char reversedResult[100];

    // Convert decimal to the desired base
    while (decimalNumber > 0) {
        reversedResult[index++] = characters[decimalNumber % outputBase];
        decimalNumber /= outputBase;
    }

    // Reverse the result string
    for (int i = index - 1, j = 0; i >= 0; i--, j++) {
        result[j] = reversedResult[i];
    }

    result[index] = '\0';
}

// Convert a number from one base to another
void convertBase(char *inputNumber, int inputBase, int outputBase, char *result) {
    // Convert the input number to decimal first
    long long decimalNumber = strtol(inputNumber, NULL, inputBase);

    // Check if conversion was successful
    if (decimalNumber == 0 && strcmp(inputNumber, "0") != 0) {
        printf("Invalid input. Please check the input number and base.\n");
        return;
    }

    convertToBase(decimalNumber, outputBase, result);
}
