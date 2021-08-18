/*
 * Program to analyze Runtime Complexity of Bubble Sort Algorithm.
 * Harshit Sharma 1910990073, 
 * Date of Submission: 27 July, 2021 
 * Coding Assignment-2
*/

#include <stdio.h>   
#include <stdlib.h>      // includes rand() function
#include <sys/time.h>    // includes gettimeofday() function

void generateRandomInput(int a[], int size);
void generateAscendingInput(int a[], int size);
void generateDescendingInput(int a[], int size);
void swap(int a[], int i, int j);
void bubble_sort(int a[], int size);
void generate_report(int initial_input_size, int increment_by);

int main() {
    
    int initial_input_size = 8000;   // initial array size
    int increment_by = 4000;         // incrementing factor each time loop runs
    
    printf("initializing");
    generate_report(initial_input_size, increment_by);

    printf("\n"); 
}

// prints the time taken by bubble sort to complete at different sizes and different types of values in the array
// parameters passed: initial_input_size of int type,initial array size, increment_by of int type, value by which size needs to be incremented each time loop runs

void generate_report(int initial_input_size, int increment_by) {
    struct timeval te;
    
    for(int i = 0; i < 7; i++) {
        int size = initial_input_size + increment_by * i;
	int a[size];
	generateRandomInput(a, size);
	gettimeofday(&te, NULL);
	long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
	bubble_sort(a, size);
	gettimeofday(&te, NULL);
	long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
	printf("\n%lld", end - start);
    }
}  

// to generate array of random numbers
// parameters passed: array of integer type i.e. a[], integer size of array i.e size
void generateRandomInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = rand() % size + 1;
    }
}

// to generate array of ascending numbers
// parameters passed: integer array a[], integer type size of array i.e. size

void generateAscendingInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = i + 1;
    }
}

// to generate array of descending numbers
// parameters passed: integer array a[], int size i.e. size of array

void generateDescendingInput(int a[], int size) {
    for(int i = 0; i < size; i++) {
        a[i] = size - i + 1;
    }
}

// to sort the array using bubble sort
// parameters passed: integer type array a[], int size for size of array

void bubble_sort(int a[], int size) {
    for(int i = 0; i < size - 1; i++) {
	int swapp = 0;
        for(int j = 0; j < size - 1 - i; j++) {
	    if(a[j] > a[j + 1]) {
		swapp = 1;
	        swap(a, j, j + 1);
	    }
	}

	if(swapp == 0) {
	    break;
	}
    }
}

// function to swap the values in array at below mentioned indexes
// parameters passed: integer type array i.e. a[], int i,j (first index, second index respectively)

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
