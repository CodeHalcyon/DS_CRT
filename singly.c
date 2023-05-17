//implementration of singly linked list
#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *Head = NULL;
void Insert_At_End(int data)
{
    struct Node *newnode,*temp;

    newnode= (struct Node*)malloc(1*sizeof(struct Node));
    newnode->data =data;
    newnode->next =NULL;

    if (Head==NULL)
        Head = newnode;
    else
    {
        temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }     
}
void Insert_At_Beg(int data)
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(1*sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    if(Head==NULL)
    {
        Head=newnode;
    }
    else
    {
        newnode->next=Head;
        Head=newnode;
    }
}
void Insert_At_Pos(int data, int pos)
{
    struct Node *newnode,*temp;
    newnode=(struct Node*)malloc(1*sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;

    temp=Head;
    while(pos-2)
    {
        temp=temp->next;
        pos--;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void Deletion_At_End()
{
    struct Node *temp,*delnode;
    temp=Head;
    if(Head==NULL)
    {
        printf("NO NODE TO DELETE");
    }
    else if(Head->next==NULL)
    {
        delnode=Head;
        Head=NULL;
        free(delnode);
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delnode=temp->next;
        temp->next=NULL;//Connection removed
        free(delnode);//node delete
    }
}
void Deletion_At_Beg()
{
    struct Node *delnode;
    if(Head==NULL)
    {
        printf("NO NODE TO DELETE");
    }
    else
    {
        delnode=Head;
        Head=Head->next;
        free(delnode);
    }
}
void Deletion_At_Pos(int pos)
{
    struct Node *temp,*delnode;
    temp=Head;
    while(pos-2)
    {
        temp=temp->next;
        pos--;
    }
    delnode=temp->next;
    temp->next=temp->next->next;
    free(delnode);
}
void Display()
{
    struct Node *newnode,*temp;
    temp = Head;
        while(temp->next!=NULL)
        {
            printf("\n%d",(temp->data));
            temp = temp->next;
        }
        temp->next = newnode;
        printf("\n%d",(temp->data));
}
int main()
{
    
    printf("\nEnter 1 to Insertion_At_Ending :-");
    printf("\nEnter 2 to Insertion_At_Beginning :-");
    printf("\nEnter 3 to Insertion_At_Position :-");
    printf("\nEnter 4 to Deletion_At_Ending :-");
    printf("\nEnter 5 to Deletion_At_Beginning :-");
    printf("\nEnter 6 to Deletion_At_Position :-");
    printf("\nEnter 7 to Display :-");
    printf("\nEnter -1 to EXIT :-\n");
    int n,data,pos;
    printf("\nEnter your choice :-\n");
    scanf("%d",&n);
    while(n!=-1)
    {
        switch(n)
        {
            case 1:
            {
             printf("Enter Data to be inserted :-");
             scanf("%d",&data);
             Insert_At_End(data);
             break;
            } 
            case 2:
            {
              printf("Enter Data to be inserted :-");
              scanf("%d",&data);
              Insert_At_Beg(data);
             break;
            }
            case 3:
            {
              printf("Enter Data and Position to be inserted :-");
              scanf("%d%d",&data,&pos);
              Insert_At_Pos(data,pos);
              break;
            }
            case 4:
            {
                Deletion_At_Beg();
               break;
            }
            case 5:
            {
             Deletion_At_End();
             break;
            }
            case 6:
            {
                printf("Enter Position to be Deleted :-");
                scanf("%d",&pos);
                Deletion_At_Pos(pos);
                break;
            }
            case 7:
            {
             Display();
             break;
            }
            default:
            {
                printf("Enter valid input :-");
            }
        }
        printf("\nEnter your Choice:-");
        scanf("%d",&n);
    }
    return 0;
}
