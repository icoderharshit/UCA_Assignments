/*
 * Program to find the GCD of two numbers using recursion.
 * Harshit Sharma 1910990073, 5 August, 2021 
 * Assignment 5 (Recursion)
*/
#include <stdio.h>
int recursive_gcd(int,int);
int main()
{
    int num1;
    int num2;
    printf("Enter two numbers:\n");
    scanf("%d %d",&num1,&num2);
    printf("GCD of entered numbers is %d",recursive_gcd(num1,num2));
    return 0;
}
// function to compute GCD
int recursive_gcd(int num1,int num2){
    if(num2==0)
    {
    return num1;
    }
    return recursive_gcd(num2,num1%num2);
}
