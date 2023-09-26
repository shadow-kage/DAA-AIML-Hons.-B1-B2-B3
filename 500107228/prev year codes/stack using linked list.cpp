#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *ptr;
}*top,*top1,*temp;

int count = 0;
void push(int data) {
     if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted:%d\n",data);
}

int pop() {
     top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    count--;
    printf("\npopped value:%d\n\n",popped);
}
void display() {
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }
    else{
    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d->", top1->info);
        top1 = top1->ptr;
    }
    printf("NULL\n\n");
    }
}

int main() {
   push(3);
   push(5);
   push(7);
   push(9);
   pop();
   display();
}

