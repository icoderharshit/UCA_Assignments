#include<stdio.h>
//defining some standard variables with their values
#define MAXSIZE 100
#define N 100

//intialize stack
int stack[MAXSIZE];
int top = -1;

void push(int item) {
    
    if(top >= MAXSIZE - 1 )
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
/*
 * Function to check whether the given stack is empty or not.
 * returns 1 : When stack is empty
 * returns 0 : When stack is not empty
 */
int is_empty()
{
    if(top<0)
        return 1;
    else
        return 0;
}

/*
 * creating a function to delete an element from the top of given stack.
 */
int pop()
{
    int item;
    if(is_empty())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}
/*
 * creating a function named peek to print the top-most element of the stack.
 */
int peek()
{
    return stack[top];
}
    
int is_balanced(char *s)
{
    char x;
    for( int i = 0; i < N ; i++ )
    {
        if( s[i] == '{' || s[i] == '(' || s[i] == '[' )
	{
	    push(s[i]);
	    continue;
	}

	if( is_empty())
	    return 1;

	switch (s[i]) {
            case ']' : x = peek();
		       pop();
		       if( x == '{' || x == '(' )
			   return 0;
		       break;
            case '}' : x = peek();
                       pop();
                       if( x == '[' || x == '(' )
                           return 0;
                       break;
            case ')' : x = peek();
                       pop();
                       if( x == '{' || x == '[' )
                           return 0;
                       break;

	}
    }
    return (is_empty());
}

int main() 
{
    char str[100];
    printf("Enter a string: ");   
    gets(str);
    int x = is_balanced(str);
    printf("%d\n",x);
    if(x == 1)
	printf("Balanced");
    else
	printf("Not Balanced");
}
