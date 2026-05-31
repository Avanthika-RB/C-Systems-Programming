#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryToDecimal(const char *binary);
int hexadecimalToDecimal(const char *hexadecimal);
char *decimalToBinary(int decimal);
char *decimalToHexadecimal(int decimal);
int power(int base, int exponent);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("invalid\n");
        return 1;
    }

    unsigned int number;
    if (strncmp(argv[2], "0b", 2) == 0) {
        number = binaryToDecimal(argv[2] + 2);
    } else if (strncmp(argv[2], "0x", 2) == 0) {
        number = hexadecimalToDecimal(argv[2] + 2);
    } else {
        //convert the number from string to int
        int num;
        if (sscanf(argv[2], "%d", &num) != 1) {
            printf("Invalid\n");
            return 1;
        }
        number = num;
    }
    if (strcmp(argv[1], "-d") == 0) {
        printf("%d\n", number);
    } else if (strcmp(argv[1], "-h") == 0) {
        printf("0x%s\n", decimalToHexadecimal(number));
    } else if (strcmp(argv[1], "-b") == 0) {
        printf("0b%s\n", decimalToBinary(number));
    } else {
        printf("Invalid.\n");
        return 1;
    }
    return 0;
}

int binaryToDecimal(const char *binary) {
    unsigned long int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += 1 << (length - i - 1); // << moves bits to left, 2^(length-i-1)
        } else if (binary[i] != '0') {
            printf("Invalid binary number.\n");
            exit(0);
        }
    }
    return decimal;
}

int power(int base, int y) {
    long int result = 1;
    for (int i = 0; i < y; i++) {
        result *= base;
    }
    return result;
}

int hexadecimalToDecimal(const char *hexadecimal) {
    unsigned long int decimal = 0;
    int length = strlen(hexadecimal);
    for (int i = 0; i < length; i++) {
        char c = hexadecimal[i];
        int digit = 0;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = 10 + (c - 'a');
        } else if (c >= 'A' && c <= 'F') {
            digit = 10 + (c - 'A');
        } else {
            printf("Invalid hexadecimal number.\n");
            exit(1);
        }
        decimal += digit * power(16, length - i - 1);
    }
    return decimal;
}

char *decimalToBinary(int decimal) {
    char *binary = (char*)malloc(33 * sizeof(char));
    if (!binary) {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    binary[0] = '\0';
    if (decimal == 0) {
        strcat(binary, "0");
    } else {
        while (decimal > 0) {
            if (decimal % 2 == 0) {
                strcat(binary, "0");
            } else {
                strcat(binary, "1");
            }
            decimal /= 2;
        }
        int length = strlen(binary);
        for (int i = 0; i < length / 2; i++) {
            char temp = binary[i];
            binary[i] = binary[length - i - 1];
            binary[length - i - 1] = temp;
        }
    }
    return binary;
}

char *decimalToHexadecimal(int decimal) {
    char *hexadecimal = (char *)malloc(9 * sizeof(char));
    if (!hexadecimal) {
        printf("memory allocation error\n");
        exit(1);
    }
    int index = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        hexadecimal[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a'); 
        // ? is a condition for left and right side : then (remainder - 10 + 'a')
        decimal /= 16;
    }
    if (index == 0){
        hexadecimal[index++] = '0';
    	hexadecimal[index] = '\0';
    }
    //reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
    return hexadecimal;
}

