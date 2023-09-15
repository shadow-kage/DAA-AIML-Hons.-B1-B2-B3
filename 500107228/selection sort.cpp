#include <stdio.h>
int main()
{
    int len;
    printf("Enter the number of elements : ");
    scanf("%d",&len);
    int a[len];
    for(int x=0;x<len;x++)
    {
        printf("a[%d] = ",x);
        scanf("%d",&a[x]);
    }
    printf("--------------------\n");
    for(int i=0;i<=len-1;i++)
    {
        printf("For pass %d:\n",i+1);
        int min_idx=i;
        for(int j=i+1;j<len;j++)
        {
            if(a[j]<a[min_idx])
            {
                min_idx=j;
            }
        if(min_idx!=i)
        {
            int temp=a[min_idx];
            a[min_idx]=a[i];
            a[i]=temp;
		}
            for(int x=0;x<len;x++)
            {
                printf("%d\t",a[x]);
            }
            printf("\n");
        }
        printf("--------------------\n");
    }
    
    printf("Sorted array : \n");
    for(int x=0;x<len;x++)
    {
        printf("%d\t",a[x]);
    }
}