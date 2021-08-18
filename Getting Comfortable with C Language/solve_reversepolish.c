/*
 * Program to evaluate Reverse Polish Expression given by user
 * Harshit Sharma 1910990073, 4 August, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include<stdio.h>
#define LIMIT 100
// function to evaluate given reverse polish expression
int reverse_polish(char* str) {
    //declaring the required variables for using the concept of stack here in this problem
    int stack[LIMIT];
    int top = -1;
    int sameN = 1;
// \0 is a null character that denotes the termination/end of string
    for(int i = 0; str[i] != '\0'; i++) {
// writing suitable if-else condition statements for evaluating the given expression with the help of stack
	if(str[i] == ' ') {
	    sameN = 1;
	    continue;
	}
	else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int first_Operand = stack[top--];
 	    int second_Operand = stack[top--];

	    if(str[i] == '+') {
	        stack[++top] = first_Operand + second_Operand;
	    }
	    else if(str[i] == '-') {
	        stack[++top] = second_Operand - first_Operand;
	    }
	    else if(str[i] == '*') {
	        stack[++top] = first_Operand * second_Operand;
	    }
	    else {
	        stack[++top] = second_Operand / first_Operand;
	    }
        }
	else {
	    if(sameN == 1) {
	        stack[++top] = str[i] - '0';
		sameN = 0;
	    }
	    else {
	        stack[top] = stack[top] * 10 + (str[i] - '0');
	    }
	}
    }
    return stack[0];
}

int main () {

    //declaring the string which will store the reverse polish expression given by user
    char str[LIMIT];
    
    printf("Enter the reverse polish expression:\n");
    // take input of required reverse polish expression from user
    scanf("%[^\n]s",str);
    
    //finally printing the desired output, i.e. result of the evaluation of the reverse polish expression
    printf("\nRequired result is %d",reverse_polish(str));

    return 0;
}