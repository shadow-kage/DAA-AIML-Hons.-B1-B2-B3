#include <stdio.h>
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
void insertAfter(struct node* prev_node, int new_data) {
  if (prev_node == NULL) {
  printf("the given previous node cannot be NULL");
  return;
  }

  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->ptr= prev_node->ptr;
  prev_node->ptr = new_node;
}
void Del(struct node *head)
{
    struct node *p;
    p=head;
    p=p->ptr;
    free(p);
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
    third->data=9;
    third->ptr=fourth;
    fourth->data=3;
    fourth->ptr=fifth;
    fifth->data=2;
    fifth->ptr=NULL;
    insertAfter(third,4);
    Del(fourth);
    tra(head);
}
