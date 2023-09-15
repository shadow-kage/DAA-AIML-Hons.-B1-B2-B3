#include<stdio.h>
int main()
{
    int arr[20],i,n,item;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
        {
        scanf("%d",&arr[i]);
        }
	printf("Enter the element to be searched:");
	scanf("%d",&item);
	int flag=0;
	for(i=0;i<n;i++)
	{
		flag+=1;
		if(arr[i]==item)
		break;
	}
	if(i<n)
	{
		printf("Element found at index:%d",i);
		printf("\nNo. of steps:%d",flag);
	}
	else
	{
		printf("Element not found!");
	}
}