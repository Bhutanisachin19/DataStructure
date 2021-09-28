#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next; // in circular we use pointer to the last node to make insertion and deletion at beginning easy
};
struct node *last;

void display()
{
    struct node *p;
    if(last == NULL)
        printf("Empty List \n");
    else
    {
        p = last->next; // 1st node
        do
        {
            printf("%d ",p->data);
            p=p->next;
        }while(p!=last->next);
        printf("\n");
    }
}

void insert_at_the_beginning()
{

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of the node \n");
    scanf("%d", &temp->data);
    temp->next = NULL;


    if(last==NULL)
    {
        last = temp;
        temp->next = last; //ppoints to itself
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
}


void insert_at_the_end()
{

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of the node \n");
    scanf("%d", &temp->data);
    temp->next = NULL;


    if(last==NULL)
    {
        last = temp;
        temp->next = last; //ppoints to itself
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}


void insert_after_a_node()
{
    int val;
    struct node *temp,*p;

    printf("Enter the value after which you want to insert a new node \n");
    scanf("%d",&val);

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of the node \n");
    scanf("%d", &temp->data);
    temp->next = NULL;


    p=last->next;

    do{
        if(p->data==val)
            break;
        p = p->next;
    }while(p!=last->next);

    if(p==last->next && p->next!=val)
        printf("Element Not Found in the list \n");
    else
    {
        temp->next = p->next;
        p->next = temp;
        if(p==last)
            last = temp;
    }
}



void delete_a_node()
{
    int val;
    struct node *temp,*p;

    printf("Enter the value which you want to delete \n");
    scanf("%d",&val);

    if(last ==NULL)
        printf("Empty List \n");
    else
    {
        //delete the only node
        if(last->next ==last && last->data==val)
        {
            temp = last;
            last = NULL;
            free(temp);
        }
        //delete the 1st node
        else if(last->next->data == val)
        {
            temp = last->next;
            last->next = temp->next;
            free(temp);
        }
        else
        {
                p= last->next;
            while(p->next!=last)
            {
                if(p->next->data == val)
                    break;

                p=p->next;
            }

            //node from in between is to be deleted
            if(p->next!=last)
            {
                temp = p->next;
                p->next= temp->next;
                free(temp);
            }
            else
            {
                if(last->data == val)
                {
                    //node to be delete is the last node
                    temp = last;
                    p->next= last->next;
                    last = p;
                    free(temp);
                }
                else
                {
                    printf("Element %d not found \n",val);
                }
            }
        }
    }

}

main()
{
    last = NULL;
    int choice;
    do
    {
        printf("Press 0 to exit \n");
        printf("Press 1  to insert elements  in the beginning of the linked list \nPress 2 to display elements from linked list \nPress 3 to insert at the end \n");
        printf("Press 4 to insert element after a node\n");
        printf("Press 5 to delete a node\n");
        printf("Enter a choice \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
                printf("Exit \n");
                break;
            case 1:
                insert_at_the_beginning();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_at_the_end();
                break;
            case 4:
                insert_after_a_node();
                break;
            case 5:
                delete_a_node();
                break;
            default:
                printf("Please enter correct choice \n");
                break;
        }
    }while(choice != 0);
}

