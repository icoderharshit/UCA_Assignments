/*
 * Program to check if the string t occurs at the end of the string s
 * Harshit Sharma 1910990073, 3 August, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>

// function to calculate length of the given string
int str_len(char* str) {
    int len=0;
    for(int i=0; str[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// function to check whether string t comes at end of s or not
int strend (char*str1, char* str2) {
    int present = 0;
    int str1_length = str_len(str1);
    int str2_length = str_len(str2);

    if(str1_length < str2_length) {
        return 0;
    }

    int index = str1_length - str2_length;

    for(int i = index; str1[i] != '\0'; i++) {
        if(str1[i] != str2[i - index]) {
	    return 0;
	    }
    }
        return 1; 
}

int main () {

    //declaring two strings
    char str1[100];
    char str2[100];

    printf("Enter String 1:\n");
    //take first string as input from user
    scanf("%[^\n]s",str1);

    printf("Enter String 2:\n");
    //take second string as input from user
    scanf(" %[^\n]s",str2);

    //printing the desired output by checking the returned value from the function call
    // int result=strend(str1,str2);
    // result!=0?printf("\nString 2 found at the end of String 1\n"):printf("\nString 2 not found at the end of String 1.");
    
    return 0;
}
