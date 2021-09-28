
//Stack on linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top;

void push()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the date of the node \n");
    scanf("%d",&temp->data);
    temp->next = NULL;

    //insert at the beginning
    if(top==NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    //removes the top , i.e remove from front
    struct node *temp;

    if(top==NULL)
        printf("Empty Stack \n");
    else
    {
        temp = top;
        top = top->next;
        //temp->next=NULL;
        printf("Element poped is %d \n",temp->data);
        free(temp);
    }
}


void disp()
{
    struct node *temp;

    if(top==NULL)
        printf("Empty stack \n");
    else
    {
        printf("Elements in the stack are \n");
        temp = top;
        while(temp!=NULL)
        {
            printf("%d \n",temp->data);
            temp = temp->next;
        }
    }
}

main()
{
    int choice;
    top = NULL;

    do
    {
        printf("Press 1  to push elements in stack \nPress 2 to pop elements from stack \nPress 3 to display the stack \nPress 4 to exit \n");

        printf("Enter a choice \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                disp();
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
