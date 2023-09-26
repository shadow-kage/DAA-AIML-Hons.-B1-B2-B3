#include <stdio.h>
#include<stdlib.h>
struct node{
    int coef,exp;
    char var;
    struct node*next;
};
create_list()
{
    int k, n;
    struct node *p, *head;
    printf ("\n How many elements toenter?");
    scanf ("%d", &n);
    for (k=0; k<n; k++)
    {
        if (k == 0) 
        {
            head = (struct node *) malloc(sizeof(struct node));
            p = head;
        }else {
            p->next = (struct node*) malloc(sizeof(struct node));
            p = p->next;
        }
        scanf ("%d %s %d", &p->coef, p->var,&p->exp);
    }
    p->next = NULL;
    return (head);
}
void display (struct node *head)
{
    int count =1; 
    struct node *p;
    p = head;
    while (p !=NULL)
    {
        printf ("\nNode %d: %d%s %d",count,coef,var,exp);
    p=p->next;
    }
}
int main()
{
   struct node *head;
   printf("ListA:");
   head = create_list();
   display(head);
}