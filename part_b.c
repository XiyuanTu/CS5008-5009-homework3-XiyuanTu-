#include <stdio.h>
#include <stdlib.h>

// Binary search function
int binarySearch(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == target) {
            return mid;
        }
        else if (array[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(&array[i], &array[minIndex]);
        }
    }
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

    selectionSort(array, size);

    int position = binarySearch(array, size, target);
    
    printf("Search result: \n%d\n", position);


    return 0;
}
