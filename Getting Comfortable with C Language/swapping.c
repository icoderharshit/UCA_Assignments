/*
 * Program to swap two variables without using third variable.
 * Harshit Sharma 1910990073, 25 July, 2021 
 * Assignment - Getting Comforable with C Language
*/

#include <stdio.h>
int main(){
int a,b;
printf("Enter two numbers: ");
scanf("%d %d",&a,&b);
a=a+b;
b=a-b;
a=a-b;
printf("The swapped numbers are %d %d\n",a,b);
        return 0;
}
