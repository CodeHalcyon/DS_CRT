#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *tail = NULL, *temp;
void InsertAtBegin(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    tail->next = head;
}

void InsertAtEnd(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
    tail->next = head;
}

void DeleteBegin()
{
    struct Node *delnode;
    delnode = head;
    if (head == NULL)
    {
        printf("ntg to delete");
    }
    else if (head->next == head)
    {
        head = NULL;
        tail = NULL;
        free(delnode);
    }
    else
    {
        head = delnode->next;
        delnode->next = NULL;
        free(delnode);
    }
    tail->next = head;
}

void DeleteEnd()
{
    struct Node *delnode;
    temp = head;
    if (head == NULL)
    {
        printf("ntg to delete");
    }
    else if (head->next == head)
    {
        head = NULL;
        tail = NULL;
        free(delnode);
    }
    else
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        delnode = temp->next;
        temp->next = head;
        tail = temp;
        free(delnode);
    }
}

void Display()
{
    struct Node *newnode, *temp;
    temp = head;
    while (temp->next != head)
    {
        printf("\n%d--%d--%d", temp, temp->data, temp->next);
        temp = temp->next;
    }
    printf("\n%d--%d--%d\n\n", temp, temp->data, temp->next);
}

int main()
{
    InsertAtEnd(10);
    InsertAtEnd(11);
    InsertAtEnd(12);
    InsertAtEnd(13);
    InsertAtEnd(99);
    Display();
    DeleteEnd();
    Display();
}