#include <stdio.h>
int main()
{
    int n, item, i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in array : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter item you want to search for : ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == item)
            break;
    }
    if (i > n-1)
        printf("Element not found");
    else
    {
        printf("Search Successful\n");
        printf("Element %d is found at position:%d", arr[i], i + 1);
        printf("\nSteps : %d",i+1);
        return 0;
    }
}