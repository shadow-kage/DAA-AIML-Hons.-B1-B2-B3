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
    for(int i=0;i<=len-2;i++)
    {
        printf("For pass %d:\n",i+1);
        for(int j=0;j<=len-i-2;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
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