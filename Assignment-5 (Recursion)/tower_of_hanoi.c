/*
 * Solution to implement the Tower of Hanoi problem.
 * Aakash Singla 1910990073, 5th August, 2021 
 * Assignment 5 (Recursion)
*/

#include <stdio.h>

// function for checking the moves in Tower of Hanoi problem
// parameters passed: integer type variable n for number of disks, char type variable from for rod to transfer disks from, char type variable to for rod to transfer disks to, char variable type aux for auxillary rod
// return int type variable for total number of movements required to implement tower of hanoi
int tower_of_hanoi(int n, char from, char to, char aux) {
    if(n == 0) {
        return 0;
    }

    int movements = 0;
    
    movements += tower_of_hanoi(n - 1, from, aux, to);
    
    printf("%c to %c\n", from, to);
    movements++;

    movements += tower_of_hanoi(n - 1, aux, to, from);

    return movements;
}

int main() {
    int num = 0;
    printf("Enter the number of disks:\n");
    scanf("%d", &num);

    int movements = tower_of_hanoi(num, 'A', 'C', 'B');
    printf("Total movements required = %d\n", movements);
}