#include <stdio.h>
void selection_sort(int *arr, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    printf("\nUnsorted array...\n");
    for (int k = 0; k < n; k++)
        printf("%d\t", arr[k]);
    selection_sort(arr, n);
    printf("\nSorted array...\n");
    for (int k = 0; k < n; k++)
        printf("%d\t", arr[k]);
    return 0;
}