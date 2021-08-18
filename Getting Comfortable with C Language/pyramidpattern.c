/*
 * Program to print pyramid pattern for entered number of steps by user.
 * Harshit Sharma 1910990073, 25 July, 2021 
 * Assignment - Getting Comforable with C Language
*/
#include <stdio.h>
int main(){
int steps;
printf("Enter the number of steps for Pyramid: ");
scanf("%d",&steps);
// variable spaces for keeping a count of spaces
int spaces=steps;
 for(int row_count=1;row_count<=steps;row_count++)
   {
        for(int prespaces=spaces;prespaces>=1;prespaces--)
        {
                printf(" ");
        }
    //phash variable for keeping a count on number of hash to be printed.
        for(int phash=1;phash<=row_count;phash++)
        {
                   printf("#");
          if(row_count!=1 && phash!=row_count)
           {
                   printf(" ");
           }
        }
                   printf("\n");
                   spaces--;
   }
// \n for printing the next iteration in next line
 printf("\n");
        return 0;
}