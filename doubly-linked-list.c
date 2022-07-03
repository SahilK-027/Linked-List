#include <stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};

void insertAtStart(struct node **start,int data)
{
    struct node *n1;
    n1=(struct node*)malloc(sizeof(struct node));
    n1->value=data;
    n1->prev=NULL;
    if(*start==NULL)
    {
        n1->next=NULL;
        *start=n1;
    }
    else
    {
        struct node *temp;
        temp=*start;
        n1->next=temp;
        temp->prev=n1;
        *start=n1;
    }
    printf("\n✅Node succesfully inserted✅\n\n");
}
void insertAtlast(struct node ** start, int data)
{
    struct node *n1;
    n1=(struct node*)malloc(sizeof(struct node));
    n1->value=data;
    n1->next=NULL;
    if(*start==NULL)
    {
        n1->prev=NULL;
        *start= n1;
    }
    else
    {
        struct node *temp;
        temp=*start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n1;
        n1->prev=temp;
    }
    printf("\n✅Node succesfully inserted✅\n\n");
}

void deleteFirstNode(struct node **start)
{
    if(*start==NULL)
    {
        printf("⚠️list is Empty⚠️\n\n");
    }
    else
    {
        struct node *temp1, *temp2;
        temp1=*start;
        temp2=*start;
        temp1=temp1->next;
        temp1->prev=NULL;
        *start=temp1;
        free(temp2);
        printf("\n✅Node succesfully deleted✅\n\n");
    }
}
void deleteLastNode(struct node **start)
{
    struct node *temp1, *temp2;
    temp1=*start;
    temp2=NULL;
    if(*start==NULL)
    {
        printf("⚠️list is Empty⚠️\n\n");
    }
    else
    {
        int count=0;
       while(temp1->next!=NULL)
       {
           temp2=temp1;
           temp1=temp1->next;
           count++;
       }
        if(count)
        {
            temp2->next=NULL;
            free(temp1);
        }
        else
        {
            *start=NULL;
            free(temp1);
        }
        printf("\n✅Node succesfully deleted✅\n\n");
    }
}
void Display(struct node* start)
{
    printf("\n🔗🔗Its Your Linked-list🔗🔗\n\n");
    struct node *temp;
    temp=start;
    if(start!=NULL)
    {
        while(temp->next!=NULL)
        {
        printf("%d ←→ ",temp->value);
        temp=temp->next;
        }
        if(temp->next==NULL)
        {
            printf("%d",temp->value);
        }
    }
    else
    {
        printf("⚠️list is Empty⚠️\n");
    }
    printf("\n\n");
}

int main()
{
    struct node *start=NULL;
    int flag=1, value;
    while(flag==1)
    {
        int ch;
        printf("\nWhat do you want to perform?\n");
        printf("ENTER YOUR CHOISE\n1. Insert At Start\n2. Insert At End\n3. DISPLAY LINKED LIST\n4. Delete First node\n5. Delete Last Node\n6. Exit\n");
        scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                        printf("Enter the data ");
                        scanf("%d",&value);
                        insertAtStart(&start,value);
                        break;
                case 2:
                        printf("Enter the data ");
                        scanf("%d",&value);
                        insertAtlast(&start, value);
                        break;
                case 3:
                        Display(start);
                        break;
                case 4:
                        deleteFirstNode(&start);
                        break;
                case 5:
                        deleteLastNode(&start);
                        break;
                case 6:
                        flag=0;
                        break;
                default:
                        printf("\n🚫Incorrect choice Re-Enter🚫\n\n");
            }
    }
    return 0;
}
