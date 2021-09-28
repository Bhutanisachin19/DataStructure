
#include<stdio.h>

void insert(int arr[]);
void delet(int arr[]);
void disp(int arr[]);

int front = -1 , rear = -1, s, element,choice;

main()
{
    printf("Enter the size Queue \n");
    scanf("%d",&s);

    int arr[s];


    do
    {
        printf("Press 1  to insert elements in queue \nPress 2 to delete elements from queue \nPress 3 to display the queue \nPress 4 to exit \n");
        printf("Enter a choice \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert(arr);
                break;
            case 2:
                delet(arr);
                break;
            case 3:
                disp(arr);
                break;
            case 4:
                printf("Exit \n");
                break;
            default:
                printf("Please enter correct choice \n");
                break;
        }
    }while(choice != 4);
}


void insert(int arr[])
{
    if(front==0 && rear==s-1)
    {
        printf("Queue IS FULL \n");
    }
    else
    {
         printf("Enter the element \n");
        scanf("%d",&element);

        if(rear == -1)
        {
            //first element
            rear = front = 0;
            arr[rear] = element;
        }
        else if(rear == s-1)
        {
            rear = 0;
            arr[rear] = element;
        }
        else
        {
            rear++;
            arr[rear] = element;
        }
    }

}


void delet(int arr[])
{
    if(front == -1)
    {
        printf("Queue IS EMPTY \n");
    }
    else
    {
         if(front == s-1)
        {
            printf("Element remove is %d \n", arr[front]);
            front = 0 ;
        }
        else if(front==rear)
        {
            printf("Element remove is %d \n", arr[front]);
            rear = front = -1;
        }
        else
        {
            printf("Element remove is %d \n", arr[front]);
            front++;
        }
    }

}

void disp(int arr[])
{
    if(front==-1 || rear==-1)
        printf("Queue is EMPTY \n");
    else
    {
        int i;
         if(front>rear)
         {
             for(i=front;i<s;i++)
             {
                 printf("%d ",arr[i]);
             }

             for(i=0;i<=rear;i++)
                printf("%d ",arr[i]);
         }
         else
         {
             for(i=front;i<=rear;i++)
             {
                 printf("%d ",arr[i]);
             }
         }
    }

}


