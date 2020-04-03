#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;

};
struct node* root=NULL;








void main()
{
   int ch;
   while(1)
   {
       printf("1:insertatbegin\n2:insertatend\n3:insertatany\n4:delete\n5:length\n6:display\n7:exit\n");
       printf("enter the choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:insertatbegin();
                break;
            case 2:insertatend();
                break;
           case 3:insertatany();
                break;
          /*  case 4:delete();
            break;*/
            case 5:length();
                    break;
           case 6:display();
            break;
            case 7:exit(0);
            break;



       }
   }
}


void insertatbegin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL)
    {

        root=temp;
        printf("first node to enroll\n");

    }
    else
    {
        temp->link=root;
        root=temp;
    }

}

void insertatend()
{

    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL)
    {
        root=temp;
        printf("first node to enroll\n");
        return;

    }
    else
    {
      struct node* p=root;
            while(p->link!=NULL)
            {
                p=p->link;

            }
            p->link=temp;
            return;

    }


}

void insertatany()
{
    struct node *temp,*p;
    int i=0;
    int location;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
        if(root==NULL)
        {
            root=temp;
            printf("first node to enroll\n");
            return;

        }
        else
        {
            printf("enter the location to enter the node\n");
            scanf("%d",&location);
            if(location>length())
            {
                printf("exceeding limit\n");
            }
            else
            {
            p=root;
                while(i<location)
                {
                  p=p->link;
                  i++;
                }
            temp->link=p->link;
            p->link=temp;
             //return;
        }
return;
}
}
void  length()
{
    int len=0;
    struct node *p;
     if(root==NULL)
     {
         printf("no nodes\n");
         printf("number of nodes is %d\n",len);
     }
     else
     {
         p=root;
            while(p!=NULL)
            {
                p=p->link;
                len++;
            }
            printf("number of node s id %d\n",len);
     }


}

void display()
{
    struct node *p;
    if(root==NULL)
    {
        printf("no elements to display\n");
    }
    else
    {
        p=root;
        while(p!=NULL)
        {
            printf("data elements is %d\n",p->data);
            printf("data address is %d\n",p->link);
            p=p->link;
        }
    }
}





















