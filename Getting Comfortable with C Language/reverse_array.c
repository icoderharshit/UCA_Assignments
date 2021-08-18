/*
 * Program to print the reverse of an array entered by user.
 * Harshit Sharma 1910990073, 27 July, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include <stdio.h>

// function to swap the values in array at index i and index j
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


// function to reverse the given array
void reverseArray(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) {
        swap(arr, i, size - i - 1);
    }
}

int main() {
    int size = 0;
    printf("Enter the size of array:\n");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter the elements of array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, size);

    printf("\nElements of the reversed array: \n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}