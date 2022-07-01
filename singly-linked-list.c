#include <stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};

void insertAtStart(struct node **start1,int data)
{
    struct node *s1;
    s1=(struct node*)malloc(sizeof(struct node));
    s1->value=data;
    s1->next= * start1;
    *start1=s1;
    printf("\n✅Node succesfully inserted✅\n\n");
}
void insertAtlast(struct node ** start2, int data)
{
    struct node *s2;
    s2=(struct node*)malloc(sizeof(struct node));
    s2->value=data;
    s2->next=NULL;
    if(*start2==NULL)
    {
        *start2=s2;
    }
    else
    {
        struct node *temp;
        temp=*start2;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=s2;
    }
    printf("\n✅Node succesfully inserted✅\n\n");
}

void deleteFirstNode(struct node **start3)
{
    if(*start3==NULL)
    {
        printf("⚠️list is Empty⚠️\n\n");
    }
    else
    {
        struct node *temp;
        temp=*start3;
        temp=temp->next;
        *start3=temp;
        free(temp);
        printf("\n✅Node succesfully deleted✅\n\n");
    }
}

void deleteLastNode(struct node **start4)
{
    if(*start4==NULL)
    {
        printf("⚠️list is Empty⚠️\n\n");
    }
    else
    {
        int count=0;
        struct node *temp1, *temp2;
        temp1=*start4;
        temp2=NULL;
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
            *start4=NULL;
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
        printf("%d -> ",temp->value);
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
        printf("What do you want to perform?\n");
        printf("ENTER YOUR CHOISE\n1. Insert At Start\n2. Insert At End\n3. DISPLAY LINKED LIST\n4. Delete First node\n5. Delete Last Node\n6. Exit\n");
        scanf("%d",&ch);
        if(ch>=1 && ch<=6)
        {
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
        }
        }
        else
        {
            printf("\n🚫Incorrect choice Re-Enter🚫\n\n");
        }
    }
    return 0;
}
