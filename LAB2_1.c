#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary using recursion
void decimalToBinary(int decimal, char *binary, int index) {
    if (index >= 0) {
        binary[index] = (decimal % 2) ? '1' : '0';
        decimalToBinary(decimal / 2, binary, index - 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <source file> <destination file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *sourceFile = argv[2];
    char *destFile = argv[3];

    FILE *inFile = fopen("numbers_f.txt", "r");
    if (inFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *outFile = fopen(destFile, "w");
    if (outFile == NULL) {
        perror("Error opening destination file");
        fclose(inFile);
        return 1;
    }

    int count = 0, decimal;
    char binary[17] = {0};

    while (fscanf(inFile, "%d", &decimal) != EOF && count < n) {
        // Initialize the binary string with zeros
        for (int i = 0; i < 16; i++) {
            binary[i] = '0';
        }

        // Convert the decimal number to binary
        decimalToBinary(decimal, binary, 15);

        // Write the result to the output file
        fprintf(outFile, "The binary equivalent of %d is %s\n", decimal, binary);

        count++;
    }

    fclose(inFile);
    fclose(outFile);

    // Display the contents of the output file
    outFile = fopen(destFile, "r");
    if (outFile == NULL) {
        perror("Error opening destination file for reading");
        return 1;
    }

    char ch;
    while ((ch = fgetc(outFile)) != EOF) {
        putchar(ch);
    }

    fclose(outFile);

    return 0;
}