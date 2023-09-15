#include <stdio.h>
int main()
{
    int a, mid, beg, end, i, j, item, flag = 0;
    printf("Enter length of array:");
    scanf("%d", &a);
    int arr[a];
    printf("Enter item:");
    scanf("%d", &item);
    printf("Enter elements in ascending order:");
    for (i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    beg = 0;
    end = a - 1;
    mid = (beg + end) / 2;
    while (beg <= end)
    {
        flag++;
        if (arr[mid] == item)
        {
            printf("Search is successful\n");
            printf("The item you serached for is %d is on position %d", arr[mid], mid + 1);
            break;
        }
        else if (arr[mid] < item)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (beg + end) / 2;
    }
    printf("\nSteps : %d", flag);
    return 0;
}