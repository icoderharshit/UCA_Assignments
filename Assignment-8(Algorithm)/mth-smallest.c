/*
 * Program - Find mth smallest number in an unsorted array
 * @Harshit Sharma , 1910990073
 * @date 20/08/2021
*/

#include<stdio.h>

// creating a function that will divide an array based on the given value

int partition (int arr[], int left, int right, int value)
{
    int i = left;
    int j = left;
    
    while (i <= right)
    {
        if (arr[i] > value)
        {
            i++;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            i++;
            j++;
        }
    }
    return j-1;
}

//creating a function that will return the mth smallest element

int mth_smallest (int arr[], int left, int right, int m)
{
    int pivot = arr[right];
    
    int pivot_idx = partition(arr, left, right, pivot);
    
    if (pivot_idx == m - 1)
    {
        return arr[pivot_idx];
    }
    else if (pivot_idx < m)
    {
        return  mth_smallest(arr, pivot_idx + 1, right, m);
    }
    else
    {
        return mth_smallest(arr, left, pivot_idx - 1, m);  
    }
}
int main()
{
    int n;
    
    printf("Enter the size of array:");
    scanf("%d", &n);

    int arr[n];
   
    printf("Enter the elements of array:");
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int m;
   
    printf("Enter the value of m:");
    scanf("%d", &m);
   
    int answer = mth_smallest(arr, 0, n - 1, m);

    printf("%d", answer);
    return 0;
}

