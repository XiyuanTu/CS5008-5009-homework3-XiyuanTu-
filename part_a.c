#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
int decimalToBinary(int decimal) {
    int binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

// Linear search function
int linearSearch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, target;
    printf("Input array size: \n");
    scanf("%d", &size);

    int *array = (int*) malloc(size * sizeof(int));
    printf("Input elements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Input target: \n");
    scanf("%d", &target);

    printf("The array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\nThe target: \n%d\n", target);

    // Convert array and target to binary
    int *convertedArray = (int*) malloc(size * sizeof(int));
    int convertedTarget;

    printf("Converted array: \n");
    for (int i = 0; i < size; i++) {
        convertedArray[i] = decimalToBinary(array[i]);
        printf("%d ", convertedArray[i]);
    }
    convertedTarget = decimalToBinary(target);
    printf("\nConverted target: \n%d\n", convertedTarget);

    // Perform linear search on converted numbers
    int position = linearSearch(convertedArray, size, convertedTarget);

    printf("Search result: \n%d\n", position);

    // Convert back to original form
    int *originalArray = (int*) malloc(size * sizeof(int));
    int originalTarget;

    printf("Original array: \n");
    for (int i = 0; i < size; i++) {
        originalArray[i] = binaryToDecimal(convertedArray[i]);
        printf("%d ", originalArray[i]);
    }
    originalTarget = binaryToDecimal(convertedTarget);
    printf("\nOriginal target: \n%d\n", originalTarget);

    free(array);
    free(convertedArray);
    
    return 0;
}
