/*
 * Program to convert a string of hexadecimal digits into its equivalent integer value.
 * Harshit Sharma 1910990073, 1 August, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>
#include<math.h>

// function to calculate length of the string
int str_len(char* str) {
    int len=0;
    for(int i=0; str[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// function to calculate the integer value of given hexadecimal number
int htoi(char* str) {
    int value = 0;
    int str_length = str_len(str);
    for(int i = (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) ? 2 : 0; i < str_length ; i++) {
	int data = 0;
	if(str[i] >= 97 && str[i] <= 102) {
	    data = str[i] - 87;
	}
	else if(str[i] >= 65 && str[i] <= 90) {
	    data = str[i] - 55;
	}
	else {
	    data = str[i] - 48;
	}
        value += data * (pow(16,str_length - i - 1)); 
    }
    return value;
}

int main () {
    char hexa_str[100];
    printf("Enter the string containing hexadecimal number:\n");
    // take the user input
    scanf("%[^\n]s", hexa_str);
    // call the htoi function created above and print the desired output.
    printf("\nInteger value of the given hexadecimal number is %d\n", htoi(hexa_str));
    return 0;
}