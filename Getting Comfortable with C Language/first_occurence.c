/*
 * Program to print the first location in the string1 where any character from the string2 occurs.
 * Harshit Sharma 1910990073, 1 August, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>

// function to find the very first occurence of any character string s1 from string s2
int any(char* s1, char* s2) {
    for(int i = 0; s1[i] != '\0' ;i++) {
        for(int j = 0; s2[j] != '\0';j++) {
	    if(s1[i] == s2[j]) {
	        return i;
	    }
	}
    }
// incase, no such matching character is found, return -1
            return -1; 
}

int main () {
    //declaring two strings
    char str1[100];
    char str2[100];

    printf("Enter String 1:\n");
    //take string1 input from user
    scanf("%[^\n]s",str1);

    printf("Enter String 2:\n");
    //take string2 input from user
    scanf(" %[^\n]s",str2);
    // int result=any(str1,str2);
    // result!=-1?printf("First Matching Character is occuring at index: %d\n", result):printf("No such matching character is found.");
    printf("\n%d\n", any(str1,str2));
    return 0;
}