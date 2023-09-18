#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *ptr;
};
void tra(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->ptr;
    }
}
int count(struct node *head)
{
    int count = 0;
while (head->ptr != NULL) {
struct node *current = head->ptr;
while (current != NULL) {
if (head->data == current->data) {
count++;
break;
}
current = current->ptr;
}
head = head->ptr;
}
printf("%d",count);
}
int main()
{
    struct node *head,*second,*third,*fourth,*fifth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    fifth=(struct node*)malloc(sizeof(struct node));
    head->data=5;
    head->ptr=second;
    second->data=7;
    second->ptr=third;
    third->data=7;
    third->ptr=fourth;
    fourth->data=7;
    fourth->ptr=fifth;
    fifth->data=2;
    fifth->ptr=NULL;
    count(head);
}