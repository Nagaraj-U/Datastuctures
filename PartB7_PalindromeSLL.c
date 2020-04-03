// Program to check if a given linked list of strings
// form a palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Link list node */
typedef struct Node
{
    char data[20];
    struct Node* next;
}Node;

// A utility function to check if str is palindrome
// or not
int isPalindromeUtil(char str[])
{
    printf("\n Inside is PalindromeUtil");
    int length = (int)strlen(str);
    printf("\n String length is %d", length);
    // Match characters from beginning and
    // end.
    for (int i=0; i<length/2; i++)
        if (str[i] != str[length-i-1])
            return 0;
    
    return 1;
}

// Returns true if string formed by linked
// list is palindrome
int isPalindrome(Node *node)
{
    printf("\n Inside isPalindrome");
    // Append all nodes to form a string
    printf("\n%s-> ", node->data);
   int length = (int)strlen(node->data);
    printf("\n String length of node->data is %d", length);
    
    char *str = (char *)malloc(sizeof(length));
     printf("\n String length of str is %d", (int)strlen(str));
    
    
    //char *stri = "x";
    ///char *str = (char *)malloc(sizeof(stri));
    
    while (node != NULL)
    {
        //str.append(node->data);
        strcat(str,node->data);
        node = node->next;
    }
    printf("\n %s",str);
    
    // Check if the formed string is palindrome
    return isPalindromeUtil(str);
}

// A utility function to print a given linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%s-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/* Function to create a new node with given data */
Node * newNode(char *str)
{
    printf("\n..in NewNode function");
    Node *new_node = (Node *)malloc(sizeof(Node));
    printf("\n..After malloc");
    strcpy(new_node->data,str);
    printf("\n..%s", new_node->data);
    new_node->next = NULL;
    return new_node;
}

/* Driver program to test above function*/
int main()
{
    Node *head = newNode("ma");
    head->next = newNode("lay");
    head->next->next = newNode("a");
    head->next->next->next = newNode("l");
    head->next->next->next->next = newNode("am");
    
    printf("\n..Calling isPalindrome function");
    int palin = isPalindrome(head);
    if(palin ==1) printf("\ntrue\n");
    else printf("\nfalse\n");
    
    //isPalindrome(head)? printf("true\n"):
    //printf("false\n");
    
    return 0;
}

