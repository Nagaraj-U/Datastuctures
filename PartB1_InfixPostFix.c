/* C Program to convert a valid Infix expression to postfix using Stacks
 Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT 
 1) (A+(B-C)*D) converted to  ABC-D*+
 2) a^b*c-d+e/f/(g+h)  converted to ab^c*d-ef/gh+/+
 3) ((a+b)*c-(d-e))^(f+g) converted to  ab+c*de--fg+^
 4) ((A+(B-C)*D)^D)^E+F converted to ABC-D*+D^E^F+
 5) A*B+(C-D/E) converted to AB*CDE/-+
 */
#include<stdio.h>
#include<ctype.h>

#define STACK_SIZE 50
#define LENGTH 50

void push(char item, int *top, char s[])
{
	
	if(*top == STACK_SIZE - 1)
	{
		printf("Stack overflow\n");
		return;
	}
	s[++(*top)] = item;
}
 
char pop(int *top, char s[])
{
	char item_deleted;

	if(*top == -1)
	{
		printf("Stack underflow\n");
		return 0;
	}
	item_deleted = s[*top];
	(*top)--;
	
	return item_deleted;
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '#':	return 0;
		
		case '(':	return 1;
		
		case '+':
		case '-':	return 2;
		
		case '*':
		case '/':	return 3;
		
		case '$':
		case '^':	return 4;
	}
}

void infix_to_postfix(char infix[], char postfix[])
{
	char symbol, s[LENGTH];
	int i, j, top;
	
	top = -1;

	push('#', &top, s);
	j = 0;
	
	while((symbol = infix[i++]) != '\0')
	{
		if(symbol == '(')
			push(symbol, &top, s);
			
		else if(isalnum(symbol))
			postfix[j++] = symbol;
			
		else if(symbol == ')')
		{
			while(s[top] != '(')
				postfix[j++] = pop(&top, s);
			pop(&top, s);
		}
		
		else
		{
			while(priority(s[top]) >= priority(symbol))
				postfix[j++] = pop(&top, s);
				
			push(symbol, &top, s);
		}
	}
	
	while(s[top] != '#')
		postfix[j++] = pop(&top, s);
	
	postfix[j] = '\0';
}

void main()
{
	char infix[LENGTH], postfix[LENGTH];
	
	printf("Enter a valid infix expression\n");
	scanf("%s", infix);
	
	infix_to_postfix(infix, postfix);
	
	printf("Given Infix expression:\t%s\n", infix);
	printf("Converted Postfix expression:\t%s\n", postfix);
}
