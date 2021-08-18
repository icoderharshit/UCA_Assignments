/*
 * Program to delete each character in string s1 that matches any character in the string s2.
 * Harshit Sharma 1910990073, 27 July, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>

// function to check whether the given string contains the passed character or not
int contains_char(char* str, char ch) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ch) {
	    return 1;
	}
    }
    return 0;
}

// function to delete every character in String s1 that matches with any character in String s2
void squeeze(char* s1, char* s2) {
    int index = 0;
    for(int i = 0; s1[i] != '\0'; i++) {
        if(contains_char(s2, s1[i]) == 0) {
	    s1[index++] = s1[i];
	}
    }
    s1[index] = '\0';
}

int main () {
    //declaring two strings
    char str1[100];
    char str2[100];

    printf("Enter the first string:\n");
    // take string 1 as input from user
    scanf("%[^\n]s", str1);

    printf("Enter the second string:\n");
    // take string 2 as input from user
    scanf(" %[^\n]s", str2);

    // call squeeze function created above to perform thae required operation
    squeeze(str1, str2);
    // finally printing the desired output
    printf("\nSqueezed String: %s\n", str1);
    return 0;
}