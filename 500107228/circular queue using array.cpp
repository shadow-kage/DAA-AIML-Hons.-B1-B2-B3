#include <stdio.h>
#include<stdlib.h>
#define maxsize 3
int queue[maxsize];
int f=-1,r=-1;
void enqueue()
{
    int element;
    printf("Value to be inserted:");
    scanf("%d",&element);
    if(f==(r+1)%maxsize)
    {
        printf("\noverflow\n");
    }
    if(f==-1 && r==-1)
    {
        f=r=0;
        queue[r]=element;
    }
    else
    {
        r=(r+1)%maxsize;
        queue[r]=element;
    }
    printf("\nvalue inserted\n");
}
int dequeue()
{
    if(f==-1 && r==-1)
    {
        printf("underflow");
    }
    int element=queue[f];
    if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f=(f+1)%maxsize;
    }
    printf("\nvalue deleted\n");
    return element;
}
void display()  
{  
    int i=f;  
    if(f==-1 && r==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {  
        printf("\nElements in a Queue are :");  
        for (i=f;i<=r;i++)  
        {  
            printf("%d ", queue[i]);  
        }  
    }  
}  
int main()
{
    printf("creating a queue\n");
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    display();
}
