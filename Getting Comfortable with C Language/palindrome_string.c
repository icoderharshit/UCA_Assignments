/*
 * Program to check whether the entered string is palindrome or not.
 * Harshit Sharma 1910990073, 25 July, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include <stdio.h>
#include <ctype.h>

//function to compare two characters if they are same or not
int sameChar(char ch1, char ch2) {
    if(ch1 >= 65 && ch1 <= 90) {
        ch1 = tolower(ch1);
    }
    if(ch2 >= 65 && ch2 <= 90) {
        ch2 = tolower(ch2);
    }

    return (ch1 == ch2) == 1 ? 1 : 0; 
}

// function to check if given string is palindrome
int isPalindrome(char str[]) {
    int size = 0;
    for(size = 0; str[size] != '\0'; size++);

    int i = 0, j = size - 1;
    while(i < j) {
	if(str[i] == ' ') {
	    i++;
	}
	else if(str[j] == ' ') {
	    j--;
	}
	else {
	    if(sameChar(str[i], str[j]) == 0) {
                return 0;
            }
            i++;
            j--;
	}
    }

    return 1;
}

int main() {
    char str[1000];

    printf("Enter the string\n"); 
    // taking input from user i.e. the required string to check if it is palindrome or not
    scanf("%[^\n]s",str);

    if(isPalindrome(str) == 1) {
        printf("\ntrue");
    }
    else {
	printf("\nfalse");
    }

    return 0;
}