#include<stdio.h>
#define SIZE 10
int stack[SIZE];
int top=-1;
int element;
int delete;

void main()
{

	int ch;
	while(1)
	{
	printf("1;push\n2;pop\n3:display\n4:exit\n");//gcc -o stack stack.c
	printf("enter the choice\n");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the element to push\n");

					scanf("%d",&element);
					push();
					break;
			case 2:pop();
					break;
			case 3:display();
					break;
			case 4:exit(0);
					printf("you exited\n");
					break;
		}
	}

}

void push()
{
	if(top==(SIZE-1))
	{
		printf("cannot push stack overflow\n");
		return;
	}
	else
	{
		stack[++top]=element;
		return;
	}
}


void pop()
{
	if(top==-1)
	{
		printf("no elements to pop\n");
		return 0;
	}
	else
	{
		delete=stack[top--];
		printf("element popped is %d\n",delete);
		//return delete;
	}
}

void display()
{
	int i=0;
	if(top==-1)
	{
		printf("no elements to display\n");
		return;
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
