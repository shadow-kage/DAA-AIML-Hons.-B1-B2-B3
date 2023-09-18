#include <stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int exp;
    struct node *next;
};
void tra(struct node *head)
{
    while(head!=NULL)
    {
        printf("%dx^%d\n",head->coef,head->exp);
        head=head->next;
    }
}
int createA(struct node *head,int n)
{
    int coef;
    int exp;
    head=(struct node*)malloc(sizeof(struct node));
    for(int i=0;i<n;i++)
    {
       struct node *new=(struct node*)malloc(sizeof(struct node));
       printf("coefficient:");
       scanf("%d",&coef);
       printf("exponent:");
       scanf("%d",&exp);
    }
    tra(head);
}
void createB(struct node *head,int n)
{
    int coef;
    int exp;
    head=(struct node*)malloc(sizeof(struct node));
    for(int i=0;i<n;i++)
    {
       struct node *new=(struct node*)malloc(sizeof(struct node));
       printf("coefficient:");
       scanf("%d",&coef);
       printf("exponent:");
       scanf("%d",&exp);
    }
    tra(head);
}
int add(int poly1,int poly2)
{
if(poly1->exp>poly2->exp)
{
    printf("%dx^%d",poly1->coef,poly1->exp);
    poly1=poly1->next;
}
else if(poly2->exp>poly1->exp)
{
    printf("%dx^%d",poly2->coef,poly2->exp);
    poly2=poly2->next;
}
else{
    int sum=poly1->coef+poly2->coef;
    printf("%dx^%d",sum,poly1->exp);
}
}
int main()
{
    int n;
    struct node *head;
    printf("ListA:\n");
    printf("No. of nodes in linked list:");
    scanf("%d",&n);
    createA(head,n);
    printf("ListB:\n");
    printf("No. of nodes in the linked list:");
    scanf("%d",&n);
    createB(head,n);
    add();
}