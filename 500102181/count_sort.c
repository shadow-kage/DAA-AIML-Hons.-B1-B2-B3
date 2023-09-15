#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximum(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void count_sort(int *arr, int n)
{
    int i, j;
    int max = maximum(arr, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i <= max; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[arr[i]] = count[arr[i]] + 1;
    i=0;
    j=0;    
    while (i<=max)
    {
        if(count[i]>0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
            i++;
    }
     
}

void print_Array(int *arr, int n)
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