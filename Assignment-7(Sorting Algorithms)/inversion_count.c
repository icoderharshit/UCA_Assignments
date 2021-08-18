/*
 * Program - Find inversion count
 * @Harshit Sharma, 1910990073
 * @date 15/08/2021 
*/

#include<stdio.h>

int merge(int* arr, int* temp, int left, int right);

/* creating a function to get inversion count
 * parameters:
 * int* arr: input array
 * int* temp: temporary array
*/

int inversion_count(int* arr, int* temp_arr,int left, int right) {
    int mid, inversion_countt = 0;

    if(left < right) {
        mid = left + (right - left) / 2;

        inversion_countt += inversion_count(arr, temp_arr, left, mid);
        inversion_countt += inversion_count(arr, temp_arr, mid + 1, right);

        inversion_countt += merge(arr, temp_arr, left, right);
    }

    return inversion_countt;
}

// creating a function to merge the arrays starting from left and mid + 1

int merge(int* arr, int* temp_arr, int left, int right) {
    int inversion_count  = 0;
    int mid = left + (right - left) / 2;
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp_arr[k++] = arr[i++];
        }
        else {
            inversion_count += mid - i + 1;
            temp_arr[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp_arr[k++] = arr[i++];
    }

    while(j <= right) {
        temp_arr[k++] = arr[j++];
    }

    int n = 0;
    for(int m = left; m <= right; m++) {
        arr[m] = temp_arr[n++];
    }
    return inversion_count;
}

int main (void) {
    int n;
    printf("No. of elements in the array\n");
    scanf("%d", &n);

    int arr[n];
    int temp_arr[n];

    printf("Enter elements in array\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Inversion count is %d\n", inversion_count(arr,temp_arr,0,n - 1));

    return 1;
}
