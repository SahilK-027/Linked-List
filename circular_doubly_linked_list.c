#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev,*next;
    int value;
};

void insertAtStart(struct node **start,int data)
{
    struct node *n1;
    n1=(struct node *)malloc(sizeof(struct node));
    n1->value=data;
    if(*start==NULL){
        n1->next=n1;
        n1->prev=n1;
        *start=n1;
    }
    else
    {
        struct node *temp;
        temp=(*start)->prev;
        n1->next=*start;
        (*start)->prev=n1;
        n1->prev=temp;
        temp->next=n1;
        *start=n1;
    }
    printf("\n✅Node succesfully inserted✅\n\n");
}
void insertAtlast(struct node **start, int data)
{
    struct node *n1;
    n1=(struct node *)malloc(sizeof(struct node));
    n1->value=data;
    if(*start==NULL){
        n1->next=n1;
        n1->prev=n1;
        *start=n1;
    }
    else
    {
        struct node *temp1,*temp2;
        temp1=*start;
        temp2=(*start)->prev;
        n1->prev=temp2;
        n1->next=temp1;
        temp1->prev=n1;
        temp2->next=n1;
    }
    printf("\n✅Node succesfully inserted✅\n\n");
}
void deleteFirstNode(struct node **start)
{
    if(*start==NULL)
    {
        printf("⚠️list is Empty⚠️\n");
    }
    else
    {
        struct node *temp1,*temp2;
        temp1=*start;
        temp2=temp1->prev;
        if(temp1==temp2)
        {
            free(temp2);
            *start=NULL;
        }
        else
        {
            temp2->next=temp1->next;
            (temp1->next)->prev=temp2;
            *start=temp1->next;
            free(temp1);
            temp1=NULL;
        }
        printf("\n✅Node succesfully deleted✅\n\n");
    }
}
void deleteLastNode(struct node **start)
{
    if(*start==NULL)
    {
        printf("⚠️list is Empty⚠️\n");
    }
    else
    {
        struct node *temp1,*temp2;
        temp1=*start;
        temp2=temp1->prev;
        if(temp1==temp2)
        {
            free(temp2);
            *start=NULL;
        }
        else
        {
            (temp2->prev)->next=temp1;
            temp1->prev=temp2->prev;
            free(temp2);
            temp2=NULL;
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
        while(temp->next!=start)
        {
            printf("%d -> ",temp->value);
            temp=temp->next;
        }
        if(temp->next==start)
        {
            printf("%d",temp->value);
        }
    }
    else
    {
        printf("⚠️list is Empty⚠️\n");
    }
    printf("\n");
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
