/*
 * Program to print n terms, every 3rd term of fibonacci series for a count of given n.
 * Harshit Sharma 1910990073, 4 August, 2021 
 * Assignment 5 (Recursion)
*/
#include <stdio.h>
void fib(int);
int main()
{
  int n;
  printf("Enter the number of terms you wanna check in the Finonnaci series:\n");
  scanf("%d",&n);
  printf("%d distinct terms occuring after every third place in the Fibonnaci series are:\n",n);
  fib(n);
  return 0;
}
//function to compute fibonacci series and print the desired output 
void fib(int n){
  int sum=1;
  //temp variable for swapping process
  int temp;
  //prev_element for storing total sum of elements before the current number
  int prev_element=1;
  for(int i=1;i<=n*3;i++){
      if(i%3==0)
      {
          printf("%d ",sum);
      }
      sum+=prev_element;
      //swapping process
      temp=sum;
      sum=prev_element;
      prev_element=temp;
  }
}
