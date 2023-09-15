#include <stdio.h>

int rec_binary_search(int *arr, int beg, int end, int item)
{
    if (beg == end)
    {
        if (arr[beg] == item)
        {
            return beg;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid = beg + (end - beg) / 2;
        if (arr[mid] == item)
            return mid;
        else if (arr[mid] < item)
        {
            return rec_binary_search(arr, mid + 1, end, item);
        }
        else
        {
            return rec_binary_search(arr, beg, mid - 1, item);
        }
    }
    return -1;
}

int main()
{
    int n, item;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in ascending order : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter item you want to search : ");
    scanf("%d", &item);
    int result = rec_binary_search(arr, 0, n - 1, item);
    if(result == -1)
        printf("Element not found");
    else
        printf("%d Elements if found at postion %d",item,result+1);
    return 0;
}