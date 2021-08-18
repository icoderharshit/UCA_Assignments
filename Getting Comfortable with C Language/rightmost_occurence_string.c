/*
 * Program to print the position of the rightmost occurrence of a string t in other string s
 * Harshit Sharma 1910990073, 2 August, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>

// function to find position of rightmost occurence of string t in string s
int str_index (char*s, char* t) {
    int flag = 0;
    int index = -1;
    for(int i = 0; s[i] != '\0'; i++) {
	flag = 0;
        if(s[i] == t[0]) {
	    for(int j = 1; t[j] != '\0'; j++) {
	        if(s[i + j] == '\0' || s[i + j] != t[j]) {
		    flag = 1;
		    break;
		}
	        }
	            if(flag == 0) {
	            index = i;
	        }
	}
        }

    return index;
}

int main () {
    //declaring two strings
    char str1[100];
    char str2[100];

    printf("Enter the String 1:\n");
    //take string1 as input from user
    scanf("%[^\n]s",str1);

    printf("Enter the String 2:\n");
    //take string2 as input from user
    scanf(" %[^\n]s",str2);

    //finally, printing the desired output by checking the returned value from the function call
    // int result=str_index(str1,str2);
    // result!=-1?printf("\nRightmost Occurrence of given string is %d\n", str_index(str1,str2)):printf("No such matching string found.");
    printf("\n%d\n", str_index(str1,str2));
    return 0;
}