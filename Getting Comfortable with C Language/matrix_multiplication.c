/*
 * Program to print the resulting matrix formed after multiplication of two given square matrices.
 * Harshit Sharma 1910990073, 26 July, 2021 
 * Assignment - Getting Comforable with C Language
*/

#include <stdio.h>
int main()
{
        //size variable for size of square matrices
        int size;
        printf("Enter the size of square matrices to be multiplied: ");
        scanf("%d",&size);
        // 2D arrays for two different square matrices
        int mat1[size][size],mat2[size][size],result_matrix[size][size];
        printf("Enter the elements of first matrix:\n");
        for(int row=0;row<size;row++)
        {
                for(int column=0;column<size;column++)
                scanf("%d",&mat1[row][column]);
                if(row==size-1)
                printf("\n");
        }
        printf("Enter the elements of second matrix:\n");
        for(int row=0;row<size;row++)
        {
                for(int column=0;column<size;column++)
                scanf("%d",&mat2[row][column]);
                if(row==size-1)
                printf("\n");   
        }
         printf("Elements of the resulting matrix after multiplication:\n");
        for(int row=0;row<size;row++)
        {
                for(int column=0;column<size;column++)
                {
                        result_matrix[row][column]=0;
                        for(int multiplying_iterator=0;multiplying_iterator<size;multiplying_iterator++)
                        {
                                result_matrix[row][column]+=mat1[row][multiplying_iterator]*mat2[multiplying_iterator][column];
                        }
                printf("%d ",result_matrix[row][column]);
                }
                printf("\n");
        }

        return 0;
}
