#include <stdio.h>

void bubble_sort(int *arr, int n)
{
    int flag = 0, c = 0, l = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Pass %d\n",i);
        for (int k = 0; k < n; k++)
            printf("%d\t", arr[k]);
        printf("\n");
        for (int j = 0; j < n - i - 1; j++)
        {
            l++;
            if (arr[j] > arr[j + 1])
            {
                flag++;
                c++;
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
                for(int j=0 ; j<n ;j++)
                    printf("%d\t",arr[j]);
                printf("\n");
            }
        }
        printf("%d swaps done",c);
        printf("\t%d non-swaps",(n-i-1)-c);
        c = 0;
        printf("\n------------------------------------\n");
    }
    printf("Total swaps : %d",flag);
    printf("\tTotal non-swaps : %d",l-flag);
}

int main()
{
    int n, i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubble_sort(arr, n);
    return 0;
}
