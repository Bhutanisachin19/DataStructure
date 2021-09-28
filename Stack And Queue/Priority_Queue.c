//priority queue on linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int priority,data;
    struct node *next;
};

struct node *start;

void insert()
{
    //insert account to priority if priority is 1 insert at beginning
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the PRIORITY of the node \n");
    scanf("%d",&temp->priority);

    printf("Enter the DATA of the node \n");
    scanf("%d",&temp->data);

    temp->next = NULL;

    if(start==NULL)
    {
        //1st node
        start = temp;
    }
    else
    {
        if(temp->priority <= start->priority )
        {
            //insert at the 1st node
            temp->next = start;
            start=temp;
        }
        else
        {
            struct node *p;
            p=start;

            while(p->next!=NULL && p->next->priority <= temp->priority)
                p=p->next;

            temp->next = p->next;
            p->next=temp;
        }
    }
}

void delete_element()
{
    //remove from 1st always in priority queue , highest priority element is removed 1st

    if(start==NULL)
        printf("Empty Queue \n");
    else
    {
        struct node *temp;

        if(start->next == NULL)
        {
            //only one element
            temp=start;
            printf("Element removed is %d \n",temp->data);
            free(temp);
            start = NULL;
        }
        else
        {
            temp = start;
            start = start->next;
            printf("Element removed is %d \n",temp->data);
            free(temp);
        }
    }
}


void display()
{
    if(start==NULL)
        printf("Empty Queue \n");
    else
    {
        struct node *temp;

        temp = start;

        while(temp!=NULL)
        {
            printf("Priority %d ",temp->priority);
            printf("Data %d \n",temp->data);
            temp = temp->next;
        }
    }
}

main()
{
    start = NULL;
    int choice;
    do
    {
        printf("Press 1 to insert in Queue \n");
        printf("Press 2 to delete from Queue \n");
        printf("Press 3 to display Queue \n");
        printf("Press 4 to EXIT\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();break;
        case 2:
            delete_element();break;
        case 3:
            display();break;
        case 4:
            printf("Exit \n");
            //exit(0); //same
            break;
        default:
            printf("Please enter correct choice \n");break;
        }
    }while(choice!=4);
}




