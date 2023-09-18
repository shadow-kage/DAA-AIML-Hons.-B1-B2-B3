#include <stdio.h>
#include<stdlib.h>
struct stack
{
  int size;
  int top;
  int *arr;
};
int Isempty(struct stack*s)
{
    if(s->top=-1)
    {
        printf("empty");
    }
    else
    {
        printf("not empty");
    }
}
int Isfull(struct stack*s)
{
    if(s->top=(s->size-1))
    {
        printf("full");
    }
    else
    {
        printf("not full");
    }
}
void push(struct stack *s,int element)
{
        s->top++;
    s->top=element;
    printf("pushed:%d\n",s->top);
}
void pop(struct stack *s)
{
    int val=s->top;
    printf("popped value:%d\n",val);
    s->top--;
}
void show(struct stack *s)
{
    printf("elements present in stack:\n");
    while(s->top>=0)
    {
        printf("%d\n",s->top);
        s->top--;
    }
}
int main(){
    struct stack *s;
    s->size=50;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    push(s,3);
    push(s,5);
    push(s,1);
    push(s,7);
    push(s,9);
    pop(s);
    show(s);
}

