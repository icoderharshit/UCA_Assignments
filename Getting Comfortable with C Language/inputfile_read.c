/*
 * Program to print all input lines that are longer than 80 characters.
 * Harshit Sharma 1910990073, 29 July, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>

// function to calculate the length of string getting read by our program at that point
int str_len(char* str) {
    int len=0;
    for(int i=0; str[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// function to print all the lines in file which are longer than 80 characters.
void print_greaterthan80() {

// input.txt is the input file of text type.
    FILE* file = fopen("./input.txt", "r"); 
    char str[1000];

//read until EOF i.e. End of File is reached
    while(fscanf(file, " %[^\n]s", str) != EOF) {
        if(str_len(str) >= 80) {
            printf("%s\n\n",str);
        }
    }

//closing the file when it is no longer in use
    fclose(file);
}

int main () {
    print_greaterthan80();
    return 0;
}