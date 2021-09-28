
/*
    Queue using circular linked list
    in circular linked list we maintain one pointer which points to the last node


    Queue
    insert from rear and exit from front
    insertion is called enqueue
    deletion is called dequeue
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *rear; //maintaining only one pointer

void enqueue()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the value of the node \n");
    scanf("%d",&temp->data);

    if(rear==NULL)
    {
        //1st node points to itself
        rear = temp;
        rear->next = rear;
    }
    else
    {
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
}


void dequeue()
{
    struct node *temp;
    //we delete from front in queue

    if(rear==NULL)
        printf("Queue is EMPTY \n");
    else
    {
        if(rear->next == rear)
        {
            //only one node
            temp = rear->next;
            rear->next = temp->next;
            printf("Element deleted is %d ",temp->data);
            free(temp);
            rear = NULL;
        }
        else
        {
            temp = rear->next;
            rear->next = temp->next;
            printf("Element deleted is %d ",temp->data);
            free(temp);
        }
    }
}

void display()
{
    if(rear==NULL)
        printf("Queus is Empty \n");
    else
    {
        struct node *temp;
        temp = rear->next;

        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        while(temp!=rear->next);
        printf("\n");
    }
}

main()
{
    rear = NULL;
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
            enqueue();break;
        case 2:
            dequeue();break;
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






