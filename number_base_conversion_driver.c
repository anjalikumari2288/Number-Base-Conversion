#include <stdio.h>
#include <assert.h>
#include "number_base_conversion_util.c"

#define MIN_BASE 2
#define MAX_BASE 36

// Unit test function
void testConversion(char *inputNumber, int inputBase, int outputBase, char *expectedResult,int i,int j) {
    char result[100];
    printf("Running (%d)/(%d) test\n",i,j);
    convertBase(inputNumber, inputBase, outputBase, result);
    if (strcmp(result, expectedResult) == 0) {
        printf("Test Passed!\n");
    } else {
        printf("Test Failed!\n");
        printf("Input: %s (Base %d) -> Expected: %s (Base %d) | Actual: %s (Base %d)\n",
               inputNumber, inputBase, expectedResult, outputBase, result, outputBase);
    }
}

int main() {
    int option;
    printf("Choose an option:\n");
    printf("1. Run Conversion\n");
    printf("2. Run Unit Tests\n");
    scanf("%d", &option);

    if (option == 1) {
        char inputNumber[100];
        int inputBase, outputBase;

        printf("Enter the number to convert: ");
        scanf("%s", inputNumber);

        printf("Enter the base of the input number (between %d and %d): ", MIN_BASE, MAX_BASE);
        scanf("%d", &inputBase);

        if (inputBase < MIN_BASE || inputBase > MAX_BASE) {
            printf("Invalid input base. Please enter a base between %d and %d.\n", MIN_BASE, MAX_BASE);
            return 1;
        }

        printf("Enter the base to convert to (between %d and %d): ", MIN_BASE, MAX_BASE);
        scanf("%d", &outputBase);

        if (outputBase < MIN_BASE || outputBase > MAX_BASE) {
            printf("Invalid output base. Please enter a base between %d and %d.\n", MIN_BASE, MAX_BASE);
            return 1;
        }

        char result[100];
        convertBase(inputNumber, inputBase, outputBase, result);
        printf("Number %s in base %d is equivalent to %s in base %d.\n", inputNumber, inputBase, result, outputBase);
    } else if (option == 2) {
        // Run unit tests
        char testCases[][4][10] = {
        {"101", "2", "10", "5"},
        {"15", "10", "16", "F"},
        {"A1", "16", "2", "10100001"},
        {"36", "36", "10", "114"},
        {"10", "10", "11", "A"},
        {"24", "24", "36", "1G"},
        {"24", "10", "25", "O"},
        {"24", "10", "23", "11"},
        {"24", "10", "24", "10"},
        {"2", "3", "10", "2"},
        {"210", "3", "10", "21"}};

        int numTests = sizeof(testCases) / sizeof(testCases[0]);
        for (int i = 0; i < numTests; ++i) {
            testConversion(testCases[i][0], atoi(testCases[i][1]), atoi(testCases[i][2]), testCases[i][3],i,numTests);
        }

    } else {
        printf("Invalid option. Please choose 1 or 2.\n");
        return 1;
    }

    return 0;
}

// gcc -o number_base_conversion_driver number_base_conversion_driver.c
// ./number_base_conversion_driver
