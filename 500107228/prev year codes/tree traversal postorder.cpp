#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createnode(int data)
{
    struct node*n;
     n=(struct node*)malloc(sizeof(struct node));
     n->data=data;
     n->left=NULL;
     n->right=NULL;
     return n;
}
void postorder(struct node *root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
int main()
{
    struct node *ptr=createnode(3);
    struct node *ptr1=createnode(7);
    struct node *ptr2=createnode(9);
    struct node *ptr3=createnode(11);
    struct node *ptr4=createnode(6);
    ptr->left=ptr1;
    ptr->right=ptr2;
    ptr1->left=ptr3;
    ptr1->right=ptr4;
    postorder(ptr);
    return 0;
}
