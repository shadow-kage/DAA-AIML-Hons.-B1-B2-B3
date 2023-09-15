#include <stdio.h>

// Bubble Sort Function
void bubble_sort(int *arr, int n)
{
    int isSorted = 0; // This will make bubble sort adaptive by decreasing the irrelevant swaps
    for (int i = 0; i < n - 1; i++) //Loop for number of passes
    {
        printf("\nWorking on pass number : %d", i + 1); // Checking the number of passes
        isSorted = 1;
        for (int j = 0; j < n - i - 1; j++) // Loop for passes in each pass
        {
            if (arr[j] > arr[j + 1]) // Comparing two adjacent elements
            {
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];  // Swapping elements if condition was true
                arr[j] = arr[j] ^ arr[j + 1];
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}

int main()
{
    int n, i;
    printf("Enter size of array : "); // Entering size of array size
    scanf("%d", &n);
    int arr[n]; // Declaring array of size n
    printf("Enter elements in array : "); // Entering elements in array
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nPrinting unsorted array : "); // Printing unsorted array
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n=====================================================\n");
    // Now printing Sorted array
    bubble_sort(arr, n); // Calling sorintg function
    printf("\n=====================================================\n");
    printf("\nPrinting sorted array : "); // Printing sorted array
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}
