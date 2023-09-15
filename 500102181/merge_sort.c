#include <stdio.h>

void print_array(int *arr, int n) // Function for printing array
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

void Merge(int *arr, int mid, int low, int high) // Merge function for merging subarrays
{
    int i = low, j = mid + 1, k = low, temp[high + 1];
    while (i <= mid && j <= high) // for merging elements from subarray after checking which one is smaller
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) // for remaing elemnts in 1st half
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high) // for remaing elemnts in 2nd half
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int r = low; r <= high; r++) // for copying elements from temporary array to main array
    {
        arr[r] = temp[r];
    }
}

void Merge_sort(int *arr, int low, int high) // For making partion of array
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        Merge_sort(arr, low, mid); // Recursive calling for dividing base array in 1st half
        Merge_sort(arr, mid + 1, high); // Recursive calling for dividing base array in 2nd half
        Merge(arr, mid, low, high); // Calling merge function for merging subarrays
    }
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in array...\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Unsorted array...\n");
    print_array(arr, n);
    printf("\nSorted array after merging...\n");
    Merge_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}
