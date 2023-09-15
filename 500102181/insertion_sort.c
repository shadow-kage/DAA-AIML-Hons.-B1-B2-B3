#include <stdio.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

void insertion_sort(int *arr, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Unsorted Array : ");
    print_array(arr, n);
    printf("\n==============================================================================\n");
    insertion_sort(arr, n);
    printf("Sorted Array : ");
    print_array(arr, n);
    return 0;
}