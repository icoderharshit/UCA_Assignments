/*
 * Program to print n fibonacci numbers that are even
 * @Harshit Sharma , 1910990073
 * @date 20/08/2021
*/
#include<stdio.h>

void fib_even(int n) {
    int first = 0;
    int second = 2;
    
    if(n == 1)
    {
        printf("0");
    }
    else if(n == 2)
    {
        printf("0 2");
    }
    else
    {
        printf("0 2 ");
        int count = 2;
        while(count < n)
        {
            int third = first + 4 * second;
            first = second;
            second = third;
        
            printf("%d ", third);
            count++;
        }
    }
}

int main()
{
    int n;
    
    printf("Enter the value of n:");
    scanf("%d", &n);

    fib_even(n);
    printf("\n");
    return 0;
}

