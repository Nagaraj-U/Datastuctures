#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void main()
{
    int len;
   int ch;
   while(1)
   {
       printf("1:addatbegin\n2;addatend\n3:addatany\n4:display\n5:length\n6:delete\n");
       printf("enter the choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
            case 1:addatbegin();
                    break;
            case 2:addatend();
                    break;
            case 3:addatany();
                    break;
            case 4:display();
                    break;
            case 5:len=length();
                    printf("length of list is %d\n",len);
                    break;
            case 6:delete();
                    break;

       }
   }
}
void addatbegin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        printf("first node to enroll\n");
        root=temp;
    }
    else
    {
        temp->right=root;
        root->left=temp;
        root=temp;
        printf("node enrolled\n");
    }

}
void addatend()
{

     struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
        printf("first node to enroll\n");

    }
    else
    {
        struct node *p;
        p=root;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
        printf("node enrolled\n");
    }
}
void addatany()
{
    int i=1;
    int location;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    printf("enter the location to add\n");
    scanf("%d",&location);
    struct node *p;
    p=root;
    while(i<location-1)
    {
        p=p->right;
        i++;

    }
    temp->right=p->right;
    p->right->left=temp;
    temp->left=p;
    p->right=temp;
    printf("node enrolled\n");
}


void display()
{
   struct node *p;
    p=root;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->right;
    }
}
int length()
{

    struct node *p;
    int len=0;
    p=root;
    while(p!=NULL)
    {
        p=p->right;
        len++;
    }
    return len;
}



void delete()
{
    int position;
    int i=1;
    struct node *p,*q;
    p=root;
    printf("enter the position\n");
    scanf("%d",&position);
    int len;
    len=length();
    if(position>len)
    {
        printf("invalid");
    }
    else if(position==1)
    {
        root=p->right;
        root->left=NULL;
        p->right=NULL;
        free(p);
        printf("first node deleted\n");
    }
    else if(position==len)
    {
        while(i<position-1)
        {
          p=p->right;
          i++;
        }
        struct node *q;
        q=p->right;
        p->right=NULL;
        q->left==NULL;
        free(q);
        printf("last node deleted\n");
    }
    else
    {


    while(i<position-1)
    {
        p=p->right;
        i++;
    }
    q=p->right;
    p->right=q->right;
    q->right->left=p;
    free(q);
    printf("node deleted\n");
}




}


