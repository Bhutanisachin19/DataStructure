/*
    queue
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

struct node *front,*rear;

void enqueue()
{
    //insert from rear i.e insert at the end

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data of the element \n");
    scanf("%d",&temp->data);

    temp->next = NULL;

    if(front==NULL && rear==NULL)
    {
        //1st element
         front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    //deletion from front
    struct node *temp;

    if(front==NULL)
        printf("Queue Empty \n");
    else
    {
        if(front==rear)
        {
            //only one element
            printf("Element deleted is %d \n",front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        else{
            printf("Element deleted is %d \n",front->data);
            temp = front;
            front = front->next;
            free(temp);
        }
    }
}

void display()
{

    if(front==NULL)
        printf("Queue Empty \n");
    else
    {
            struct node *temp;
            temp = front;
            while(temp!=NULL)
            {
                printf("%d ",temp->data);
                temp=temp->next;
            }
    }
}

main()
{
    front = rear = NULL;

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



