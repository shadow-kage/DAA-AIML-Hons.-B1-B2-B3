#include <stdio.h>

void print_array(int *arr, int n) // Function for printing array
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

int partition(int arr[], int low, int high) // For returning pivot position after each swap
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do // used do while for atleast run this once
    {
        while (arr[i] <= pivot) // For finding element greater than pivot
            i++;
        while (arr[j] > pivot) // For finding element smaller than pivot
            j--;
        if (i < j)
        {
            temp = arr[i]; // Swapping ith and jth element until i and j are not overlapped
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];  // Swapping pivot and jth element after i and j crossed each other
    arr[low] = arr[j];
    arr[j] = temp;
    return j; //Returning pivot
}

void quick_sort(int arr[], int low, int high) // for making sub arrays
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high); // Position of pivot
        quick_sort(arr, low, partitionIndex - 1); // Dividing array in first half
        quick_sort(arr, partitionIndex + 1, high); // Dividing array in second half
    }
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in array : ", n);
    for (int k = 0; k < n; k++)
        scanf("%d", &arr[k]);
    printf("Unsorted array...\n");
    print_array(arr, n);
    printf("\n============================================\n");
    printf("Sorted array...\n");
    quick_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}
