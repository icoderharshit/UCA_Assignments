/*
 * Program to implement stack in C
 * @Harshit Sharma, 1910990073
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

//intialize stack
//
int stack[MAXSIZE];
int top = -1;

//Function to push an element at top of the stack
void push() { 
    int x;
    if(top >= MAXSIZE - 1 )
    {
        printf("Stack Overflow");
	return;
    }
    else
    {
	printf("Enter an element to be inserted: ");
	scanf("%d",&x);
        top++;
	stack[top] = x;
    }
}

/*
 * Function that checks whether the stack is empty or not
 * returns 1 : when stack is empty
 * returns 0 : when stack is not empty
 */
int is_empty()
{
    if( top < 0 )
	return 1;
    else
	return 0;
}

//Function to delete element from top of the stack and returns it

int pop()
{
    int item;
    if( is_empty() )
    {
	printf("Stack Underflow\n");
    }
    else
    {
        item = stack[top];
	top--;
	printf("Element Popped: %d\n", item);
	return item;
    }
}

//Function to print the topmost element of the stack

void peek()
{
    printf("Element At Top Of The Stack : %d",stack[top]);
}

//Function to print elements in stack

void print() {
    for(int i = 0 ; i <= top ; i++ )
    {
        printf("%d\n",stack[i]);
    }
}

int main()
{
    int option;
    printf("\nStack Operations:");
    printf("\n1. Push \n2. Pop \n3. Peek \n4. Print Stack \n5. Exit");
    while(1)
    {
	printf("\nEnter an operation: ");
	scanf("%d",&option);

	switch(option)
	{
	    case 1: push();
		    break;
            case 2: pop();
		    break;
	    case 3: peek();
		    break;
	    case 4: print();
		    break;
	    case 5: exit(0);

	    default: printf("Enter Valid Operation\n");
		     break;
	}
    }
    
}
