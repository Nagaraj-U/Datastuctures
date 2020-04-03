#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;

};
struct node* tail;


int main()
{
        int ch;
        int len;
        while(1)
        {
            printf("1:addatend\n2:addatabegin\n3:addatany\n4:len\n5:display\n6:deleteatbegin\n7:deleteatend\n8:deleteatany\n");
            printf("enter the choice\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:addatend();
                break;
                case 2:addatbegin();
                        break;
                case 3:addatany();
                            break;
                case 4:len=length();
                        printf("no of nodes is %d\n",++len);
                        break;
                case 5:display();
                        break;
                case 6:deleteatbegin();
                    break;
                case 7:deleteatend();
                break;
                case 8:deleteatany();
                break;
            }
        }
}
void addatend()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(tail==NULL)
    {

        printf("first node\n");
        tail=temp;
        tail->link=temp;
    }
    else
    {
        temp->link=tail->link;
        tail->link=temp;
        tail=temp;
        printf("$\n");
    }
}


void addatbegin()
{
      struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(tail==NULL)
    {
        printf("first node to enroll\n");

        tail->link=temp;
        tail=temp;
    }
    else
    {

       temp->link=tail->link;
       tail->link=temp;

       printf("#\n");

    }

}
void addatany()
{
    int loc;
    struct node* temp;
    struct node *p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    printf("enter the location  to add\n");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("exceeding location\n");
    }
    else
    {


    int i=1;
    p=tail->link;
    while(i<loc-1)
    {
            p=p->link;
            i++;
    }
    temp->link=p->link;
    p->link=temp;
    printf("*");
    }

}
int length()
{
    int len=0;
    struct node* p;
    p=tail->link;
    while(p!=tail)
    {
        len++;
        p=p->link;
    }
    return len;
}
void display()
{
    struct node *p;
    p=tail->link;
    while(p!=tail)
    {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("%d\n",tail->data);
}

void deleteatbegin()
{
    int l;
    struct node *temp;
    temp=tail->link;




    if(tail==NULL)
    {
        printf("no nodes to delete\n");
    }
    else if(temp->link==temp)
    {
        tail==NULL;
        free(temp);
    }
    else
    {
        tail->link=temp->link;
        temp->link==NULL;
        free(temp);
        printf("you deleted first node\n");


    }
}

void deleteatend()
{
    struct node *current,*previous;
    current=tail->link;
    if(tail==NULL)
    {
        printf("no nodes to delete\n");
    }
    else if(current->link==current)
    {
        tail=NULL;
        free(current);
        printf("deleted single node\n");
    }
    else
    {
        while(current->link!=tail->link)
        {
            previous=current;
            current=current->link;
        }
       previous->link=tail->link;
       tail=previous;
       current=NULL;
       free(current);
       printf("\ndeleted last node");

    }
}
void deleteatany()
{

    int l,i;
    l=length();
    printf("enter the location to delete");
    scanf("%d",&i);
    if(i>l||i<1)
    {
        printf("invalid position\n");
    }
    else
    {
        struct node *temp,*p;
        temp=tail->link;
        int j=1;
        while(j<i-1)
        {
            temp=temp->link;
            j++;
        }
        p=temp->link;
        temp->link=p->link;
        p->link=NULL;
        free(p);
        printf("node at position %d is deleted",l);
    }

}




