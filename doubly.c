#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *Head = NULL;

void InsertionAtEnd(int data)
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(1 * sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (Head == NULL)
    {
        Head = newnode;
    }
    else
    {
        temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void InsertionAtBegin(int data)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(1 * sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (Head == NULL)
    {
        Head = newnode;
    }
    else
    {
        newnode->next = Head;
        Head->prev = newnode;
        Head = newnode;
    }
}
void InsertAtRandom(int data, int pos)
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(1 * sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
        temp = Head;
        while (pos - 2)
        {
            temp = temp->next;
            pos--;
        }
        newnode->next = temp->next;
        newnode->prev=temp;
        temp->next->prev = newnode;
        temp->next=newnode;
}

void DeleteAtBegin(){
    struct Node *delnode;
    if(Head==NULL)
        printf("no node to delete");
    else if (Head->next==NULL)
    {
        delnode=Head;
        Head=NULL;
        free(delnode);
    }
    else
    {
        delnode = Head;
        Head=Head->next;
        Head->prev = NULL;
        free(delnode);
    }
}

void DeleteAtEnd(){
    struct Node *delnode,*temp;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    delnode=temp;
    delnode->prev->next=NULL;
    delnode->prev=NULL;
    free(delnode);

}

void Display()
{
    struct Node *temp;
    temp = Head;
    while (temp->next != NULL)
    {
        printf("%d -- %d -- %d -- %d\n",temp->prev,temp, temp->data, temp->next);
        temp = temp->next;
    }
    printf("%d -- %d -- %d -- %d",temp->prev,temp, temp->data, temp->next);
}
int main()
{
    InsertionAtBegin(1);
    InsertionAtBegin(2);
    InsertionAtBegin(14);
    InsertionAtBegin(5);
    InsertionAtBegin(10);
    DeleteAtBegin();
    
    Display();

    return 0;
}