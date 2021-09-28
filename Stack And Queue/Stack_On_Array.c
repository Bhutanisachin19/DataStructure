//stack using array


#include<stdio.h>

void push(int arr[]);
void pop(int arr[]);
void display(int arr[]);

int s, choice, element;
int top = -1;

main()
{
    printf("Enter the size of stack \n");
    scanf("%d", &s);

    int arr[s];

    do
    {

        printf("Press 1  to push elements in stack \nPress 2 to pop elements from stack \nPress 3 to display the stack \nPress 4 to exit \n");

        printf("Enter a choice \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push(arr);
                break;
            case 2:
                pop(arr);
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

void push(int arr[])
{
    //printf("Push called \n");

    if(top == s-1)
        printf("STACK IS FULL \n");
    else
    {
            printf("Enter the element to be inserted \n");
            scanf("%d",&element);


        if(top == -1)
        {
            //1st element
            top = 0;
            arr[top] = element;
        }
        else
        {
            top++;
            arr[top] = element;
        }
    }
}


void pop(int arr[])
{
    //printf("Pop called \n");

     if(top == -1)
        printf("STACK IS EMPTY \n");
    else
    {
        printf("Element poped is %d \n", arr[top]);
        top--;
    }
}


void disp(int arr[])
{
    int i=0;
    printf("The Stack is \n");

    printf("_____\n");
    for(i=top;i>=0;i--)
    {
        printf("| %d |\n",arr[i]);
        printf("_____\n");

    }
    printf("\n");
}
