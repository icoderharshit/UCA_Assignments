/*
 * Program to implement the standard/most used string functions in string.h library such as strncpy, strncat, and strncmp
 * Harshit Sharma 1910990073, 3 August, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>

// function to calculate the length of string
int _strlen(char* str) {
    int len=0;
    for(int i=0; str[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// function to copy n characters from string t to string s
void _strncpy(char* str1 ,char* str2, int n) {
    int str2_length = _strlen(str2);

    for(int i = 0; i < n; i++) {
        str1[i] = (i < str2_length) ? str2[i] : '\0';
    }

}

// function to do catenation of n characters from string t to string s
void _strncat(char* str1, char* str2, int n) {
    int str1_length = _strlen(str1);

    for(int i = str1_length; i - str1_length < n ; i++) {
        str1[i] = str2[i - str1_length];
    }
    str1[str1_length + n] = '\0';
}

// function to compare n characters of given two strings
int _strncmp(char* str1, char* str2, int n) {
    for(int i = 0; i < n; i++) {
        if(str1[i] > str2[i]) {
	    return 1;
	}

	if(str1[i] < str2[i]) {
	    return -1;
	}
    }

    return 0;
}

int main () {

    //declaring the two strings and check named string
    char str1[100];
    char str2[100];
    char check[100];
    int n = 0;

    printf("Enter the string:\n");
    scanf("%[^\n]s",str1);

    printf("Enter the other string:\n");
    scanf(" %[^\n]s",str2);

    printf("No. of characters for which u want to perform these operations:\n");
    scanf("%d",&n);
    
    //finally, making a call to each of the function created above and passing the required parameters and then printing the desired output
    _strncat(str1,str2,n);
    printf("After performing concatenation of %d characters,output of str is %s\n",n,str1);

    printf("Output of strncmp is %d\n", _strncmp(str1,str2,n));

    _strncpy(check,str1,str2);
    printf("After copying %d characters from string t to new string,output is %s\n",n,check);
    
    return 0;
}