/*
 * Analysis of Runtime Complexity of Selection Sort Algorithm.
 * Submitted by Harshit Sharma 1910990073, 31 July 2021 
 * Assignment 2 (Continued)
*/

#include <stdio.h>   
#include <stdlib.h>      // includes rand() 
#include <sys/time.h>    // includes gettimeofday()

void generateRandomInput(int a[], int size);
void generateAscendingInput(int a[], int size);
void generateDescendingInput(int a[], int size);
void swap(int a[], int i, int j);
void selection_sort(int a[], int size);
void generate_report(int initial_input_size, int increment_by);

int main() {
    
    int initial_input_size = 8000;   // size of array
    int increment_by = 4000;         // incremental factor each time loop runs
    
    printf("starting");
    generate_report(initial_input_size, increment_by);
    printf("\n"); 
}

// prints the time taken by selection sort to complete at different sizes and different types of values in the array
// int initial_input_size for initial size of array, integer type variable increment_by for value by which size needs to be incremented each time loop runs
void generate_report(int initial_input_size, int increment_by) {
    struct timeval te;
    
    for(int i = 0; i < 7; i++) {
        int size = initial_input_size + increment_by * i;
	int a[size];

	generateDescendingInput(a, size);
	gettimeofday(&te, NULL);
	long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
	selection_sort(a, size);
	gettimeofday(&te, NULL);
	long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

	printf("\n%lld", end - start);
    }
}  

// for generating array with random numbers
// integer type array a[] - array of integers, integer type variable size for array size 

void generateRandomInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = rand() % size + 1;
    }
}

// for generating array with random numbers
// integer type array a[] - array of integers, integer type variable size for array size

void generateAscendingInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = i + 1;
    }
}

// for generating array of descending numbers
// integer type array a[] - array of integers, integer type variable size for array size

void generateDescendingInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = size - i + 1;
    }
}

// function for sorting the array using selection sort algorithm
// integer type array a[] - array of integers, integer type variable size for array size

void selection_sort(int a[], int size) {
    for(int i = 0; i < size - 1; i++) {
	int minIndex = i;
        for(int j = i + 1; j < size; j++) {
	    if(a[j] < a[minIndex]) {
		minIndex = j;
	    }
	}

	if(i != minIndex) {
	    swap(a, i, minIndex);
	}
    }
}

// swapping the numbers in array at indexe i and index j
// integer type array a[] - array of integers, integer type variable i for first index, integer type variable j for second index

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
