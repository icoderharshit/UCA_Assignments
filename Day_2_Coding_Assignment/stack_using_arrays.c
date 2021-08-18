/*
 * Program to implement the Stack in C using Arrays.
 * Harshit Sharma 1910990073, 4th August 2021 
 * Day_2_Coding_Assignment
*/

#include <stdio.h>
#include <stdlib.h>
#define capacity 100

//global variables for implementing the stack using arrays with the standard naming convention already being followed
void push(int);
int pop();
int peek();
int is_empty();
int top=-1;
int stack[capacity];
int element_to_push;
int ret_value;
int main(){
    int option;
printf("Implementation of Stack in C using Arrays\nYou have four options of choice:\n1.Press 1 for push() operation\n2.Press 2 for pop() operation\n3.Press 3 for peek() operation\n4.Press 4 for is_empty() operation\n5.Press 5 for exit\n");
// loop for asking the user to enter an option until exit operation is called i.e. Option 5
    do{
printf("Choose an Option: \n");
scanf("%d",&option);
switch(option)
{
    case 1:
    printf("Enter the number to be pushed: ");
    scanf("%d",&element_to_push);
    push(element_to_push);
    break;
    
    case 2:
    ret_value=pop();
    ret_value==-1?printf("Stack Underflow\n"):printf("%d popped out of the stack\n",ret_value);
    break;

    case 3:
    ret_value=peek();
    ret_value==-1?printf("Stack Underflow\n"):printf("%d is present at top of the stack\n",ret_value);
    break;

    case 4:
    is_empty()==1?printf("The given stack is empty.\n"):printf("Stack not empty.\n");
    break;

    case 5:
    printf("Program Terminated.");
    exit(0);
    break;

    default:
    printf("Invalid Operation, please enter a valid option.\n");

}
    } while(option!=5);     
    return 0;
}
// function for insertion/push of an element in the stack
void push(int element){
if(top==capacity-1)
{
    printf("Stack Overflow\n");
}
else{
    top++;
    stack[top]=element;
    printf("%d pushed to the stack\n",element);
}
}

// function to pop an element from the stack
int pop(){
    int return_value;
    if(top==-1)
    {
        return_value=-1;
    }
    else{
        return_value=stack[top];
        top--;    
        }
    return return_value;
}

// function to return peek/top element in the stack
int peek(){
    int return_value;
    if(top==-1){
    return_value=-1;
    }
    else{
    return_value=stack[top];
    }
    return return_value;
}

// function for checking if the stack is empty or not
int is_empty(){
    if(top==-1)
    {
        return 1;
    }
        return 0;
}