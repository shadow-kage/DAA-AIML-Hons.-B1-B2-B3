#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // As the name suggests this header file is for limits of datatypes

int maximum(int *arr, int n)
{
    int max = INT_MIN; // Min value an interger can hold = –2147483648 for a 32-bits
    for (int i = 0; i < n; i++) // Finding maximum element in array 
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max; // Returning maximum element
}

void count_sort(int *arr, int n) // Count sort function
{
    int i, j;
    int max = maximum(arr, n); // Giving maximum element in array
    int *count = (int *)malloc((max + 1) * sizeof(int)); // Creating an auxilary array of size equal to (maximum_element+1)
    for (i = 0; i <= max; i++)
        count[i] = 0; // Initializing auxilary array with each element as 0
    for (i = 0; i < n; i++)
        count[arr[i]] = count[arr[i]] + 1; // Pushing elements in count array(auxilary)
    i=0;
    j=0;    
    while (i<=max) 
    {
        if(count[i]>0) // Pushing elements back in main array in sorted form
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
     
}

void print_Array(int *arr, int n) // Function to print array
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in array : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Unsorted array...\n");
    print_Array(arr, n);
    printf("\nSorted array...\n");
    count_sort(arr, n);
    print_Array(arr, n);
}
