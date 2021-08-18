/*
 * Program to convert Infix expression to Postfix expression
 * @author Harshit Sharma, 1910990073 
 * @date 17/07/2021
 * Assignment-4 (Stacks and Queues)
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 100
//defining standard required variables
int stack[MAXSIZE];
int top = -1;

int is_empty()
{
    if( top == -1 )
	return 1;
    else
	return 0;
}

void push(int item)
{
    if( top + 1 == MAXSIZE )
    {
        printf("Stack Overflow");
    }
    top++;
    stack[top] = item;
}

int pop()
{
    if(is_empty())
    {
        printf("Stack Underflow");
    }
    int y = stack[top];
    top--;
    return y;
}

//creating a function that will return the precedence of the passed operator
int prec( char c )
{
    if( c == '*' || c == '/' )
	return 2;
    else if( c == '+' || c == '-' )
	return 1;
    else
	return -1;
}

int peek()
{
    return stack[top];
}

//creating a function to convert Infix expression into Postfix experssion
void infix_to_postfix(char *exp)
{
    int k = -1;
    int i;
    for (i = 0, k = -1; exp[i]; i++)
    {
        if (isdigit(exp[i]))
            exp[++k] = exp[i];
         
        else if (exp[i] == '(')
            push(exp[i]);
        
        else if (exp[i] == ')')
        {
            while (!is_empty() && peek() != '(')
                exp[++k] = pop();
            if (!is_empty() && peek() != '(')
                return -1;             
            else
                pop();
        }
        else
        {
            while (!is_empty() && prec(exp[i]) <= prec(peek(stack)))
                exp[++k] = pop();
            push(exp[i]);
        }
 
    }
    while (!is_empty())
        exp[++k] = pop();

    exp[++k] = '\0';
    puts(exp);
}

int main()
{
    char str[MAXSIZE];
    printf("Enter an expression:");
    gets(str);
    infix_to_postfix(str);

}
