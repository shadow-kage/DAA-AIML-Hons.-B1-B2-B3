#include <stdio.h>
int stack[10];
int max_size=10;
int top=-1;
void push(int element)
{
        top++;
    stack[top]=element;
    printf("pushed:%d\n",stack[top]);
}
void pop()
{
    int val=stack[top];
    printf("popped value:%d\n",val);
    top--;
}
void show()
{
    printf("elements present in stack:\n");
    while(top>=0)
    {
        printf("%d\n",stack[top]);
        top--;
    }
}
int main()
{
    push(3);
    push(5);
    push(7);
    push(9);
    pop();
    show();
    return 0;
}

