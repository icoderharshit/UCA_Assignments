/*
 * Program to implement selection sort using Recuesion.
 * Harshit Sharma 1910990073, 4 August, 2021 
 * Assignment 5 (Recursion)
*/
#include <stdio.h>
int minIndex(int *,int,int);
void recursiveSort(int *,int,int);
int main()
{
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    recursiveSort(arr,n,0);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
//function to check minimum index
int minIndex(int *arr,int i,int j){
    if(i==j)
    {
    return i;
    }
    int k=minIndex(arr,i+1,j);
    return (arr[i]<arr[k])?i:k;
}
//recursive function to perform selection sort
void recursiveSort(int *arr,int n,int index){
    if(index==n)
    return;
    int k=minIndex(arr,index,n-1);
    if(k!=index)
    {
        int temp=arr[k];
        arr[k]=arr[index];
        arr[index]=temp;
    }
    recursiveSort(arr,n,index+1);
}
