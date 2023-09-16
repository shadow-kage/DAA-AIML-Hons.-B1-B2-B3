#include <stdio.h>
void selection_sort(int *arr, int n)
{
    int i, j, min, temp, flag = 0, c = 0, l = 0;
    for (i = 0; i < n - 1; i++)
    {
        printf("Pass %d\n", i);
        for (int k = 0; k < n; k++)
            printf("%d\t", arr[k]);
        printf("\n");
        min = i;
        for (j = i + 1; j < n; j++)
        {
            l++;
            if (arr[j] < arr[min])
            {
                min = j;
                flag++;
                c++;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        for (int k = 0; k < n; k++)
            printf("%d\t", arr[k]);
        printf("\n");
        printf("%d swaps done", c);
        printf("\t%d non-swaps", (n - i - 1) - c);
        c = 0;
        printf("\n------------------------------------\n");
    }
    printf("Total swaps : %d", flag);
    printf("\tTotal non-swaps : %d", l - flag);
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
    selection_sort(arr, n);
    return 0;
}
