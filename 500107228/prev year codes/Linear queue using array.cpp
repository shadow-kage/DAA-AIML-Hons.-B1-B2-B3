#include <stdio.h>
#include<stdlib.h>
#define maxsize 5
int queue[maxsize];
int r=-1;
int f=-1;
void enqueue()  
{  
    int element;  
    printf("\nEnter the element:\n");  
    scanf("\n%d",&element);      
    if(r == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(f == -1 && r == -1)  
    {  
        f = 0;  
        r = 0;  
    }  

    else
    {
        r++;
    }
    queue[r]=element;
    printf("\nvalue inserted\n");
}
int dequeue()
{
    if(f==r==-1)
    {
        printf("underflow");
    }
    int item=queue[f];
    if(f==r)
    {
        f=r=-1;
    }
    else{
        f++;
    }
    printf("\nvalue deleted\n");
    return item;
}
void display()  
{  
    int i;  
    if(r == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        for(i=f;i<=r;i++)  
        {  
            printf("\n%d\n",queue[i]);  
        }     
    }
}    
int main()
{
    printf("Creating a queue\n");
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    display();
}