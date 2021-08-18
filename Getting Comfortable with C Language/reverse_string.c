/*
 * Program to reverse the string entered by user and print it.
 * Harshit Sharma 1910990073, 1 August, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>

// function to calculate length of the string
int str_len(char* str) {
    int len=0;
    for(int i=0; str[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// function to reverse the given string, takes reference to character array (as parameter) 
void reverse_string(char* str) {
    int str_length = str_len(str);
    for(int i = 0; i < str_length / 2 ; i++) {
	char temp = str[i];
        str[i] = str[str_length - i - 1];
	str[str_length - i - 1] = temp;
    }
}

int main () {
    char str[100];

    printf("Enter the string\n");
    // take the input of string from user
    scanf("%[^\n]s",str);

    //call the function to reverse the given string
    reverse_string(str);

    printf("Reversed string is:\n");
    //printing the reversed string
    printf("%s\n",str);
    return 0;
}