#include <stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};

void insertAtStart(struct node **last,int data)
{
    struct node *n1;
    n1=(struct node*)malloc(sizeof(struct node));
    n1->value=data;
    if(*last==NULL)
    {
        n1->next=n1;
        *last=n1;
    }
    else
    {
        struct node *temp;
        temp=*last;
        n1->next=temp->next;
        temp->next=n1;
    }
    printf("\n✅Node succesfully inserted✅\n\n");
}
void insertAtlast(struct node **last, int data)
{
    struct node *n1;
    n1=(struct node*)malloc(sizeof(struct node));
    n1->value=data;
    if (*last==NULL)
    {
        n1->next=n1;
        *last=n1;
    }
    else
    {
        struct node *temp;
        temp=*last;
        n1->next=temp->next;
        temp->next=n1;
        *last=n1;
    }
    printf("\n✅Node succesfully inserted✅\n\n");
}
void deleteFirstNode(struct node **last)
{
    if(*last==NULL)
    {
        printf("⚠️list is Empty⚠️\n\n");
    }
    else
    {
        struct node *temp1, *temp2;
        temp1=*last;
        temp2=temp1->next;
        if(temp1!=temp2)
        {
            temp1->next=temp2->next;
            free(temp2);
        }
        else
        {
            *last=NULL;
            free(temp2);
        }
        printf("\n✅Node succesfully deleted✅\n\n");
    }
}
void deleteLastNode(struct node **last)
{
    if(*last==NULL)
    {
        printf("⚠️list is Empty⚠️\n\n");
    }
    else
    {
        struct node *temp1,*temp2;
        temp1=*last;
        if(temp1->next==*last)
        {
            *last=NULL;
            free(temp1);
        }
        else
        {
            temp2=*last;
            while(temp1->next!=*last)
            {
                temp1=temp1->next;
            }
            temp1->next=temp2->next;
            *last=temp1;
            free(temp2);
        }
        printf("\n✅Node succesfully deleted✅\n\n");
    }
}
void Display(struct node* last)
{
    printf("\n🔗🔗Its Your Linked-list🔗🔗\n\n");
    struct node *temp;
    temp= last;
    if(temp==NULL)
    {
        printf("⚠️list is Empty⚠️\n");
    }
    else
    {
        while(temp->next!=last)
        {
            temp=temp->next;
            printf("%d --> ",temp->value);
        }
        if(temp->next==last)
        {
            printf("%d",last->value);
        }
    }
}

int main()
{
    struct node *last=NULL;
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
                    insertAtStart(&last,value);
                    break;
                case 2:
                        printf("Enter the data ");
                        scanf("%d",&value);
                        insertAtlast(&last, value);
                        break;
                case 3:
                        Display(last);
                        break;
                case 4:
                        deleteFirstNode(&last);
                        break;
                case 5:
                        deleteLastNode(&last);
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
