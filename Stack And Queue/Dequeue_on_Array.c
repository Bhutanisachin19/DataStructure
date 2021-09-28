// entry and exit from anywhere

#include<stdio.h>
#include<stdlib.h>
#define MAX 500

int arr[MAX];
int front , rear;

void insertFront()
{
    int val;
    printf("Enter the value of the node \n");
    scanf("%d",&val);

    if(front==-1)
        front=rear=0;
    else if(front==0)
        front = MAX-1;
    else
        front = front-1;

    arr[front] = val;
}

void insertRear()
{
    int val;
    printf("Enter the value of the node \n");
    scanf("%d",&val);

    if(rear==-1)
        rear=front=0;
    else if(rear==MAX-1) //what if front is at 0 ?
        rear=0;
    else
        rear++;

    arr[rear] = val;
}

void delete_front()
{
    if(front==-1)
        printf("Empty QUeue \n");
    else if(front==rear)
    {
        front = rear = -1;
    }
    else if(front==MAX-1)
        front = 0;
    else
        front++;
}

void delete_Rear()
{

    if(front==-1)
        printf("Empty QUeue \n");
    else if(front==rear)
    {
        front = rear = -1;
    }
    else if(rear==0)
        rear=MAX-1;
    else
        rear--;
}

void display()
{
    //same as circular queue

    int i;
    i=front;
    if(front==-1)
        printf("Empty Queue \n");
    else if(front<=rear)
    {
        while(i<=rear)
            printf("%d",arr[i++]);
    }
    else
    {
        while(i<=MAX-1)
            printf("%d",arr[i++]);

        i=0;
        while(i<=rear)
            printf("%d",arr[i++]);
    }
    printf("\n");
}


main()
{
    front =rear =-1;
    int choice;
    do
    {
        printf("Press 1 to insert in front of Queue \n");
        printf("Press 2 to insert in rear of Queue \n");
        printf("Press 3 to delete from front Queue \n");
        printf("Press 4 to delete from rear in Queue \n");
        printf("Press 5 to display Queue \n");
        printf("Press 0 to EXIT\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insertFront();break;
        case 2:
            insertRear();break;
        case 3:
            delete_front();break;
        case 4:
            delete_Rear();break;
        case 5:
            display();break;
        case 0:
            printf("Exit \n");
            //exit(0); //same
            break;
        default:
            printf("Please enter correct choice \n");break;
        }
    }while(choice!=0);
}






