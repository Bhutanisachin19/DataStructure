
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start;


void display_from_front()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("EMPTY LIST \n");
    }
    else
    {
        temp = start;
        while(temp!=NULL)
        {
             printf("%d ", temp->data);
            temp= temp->next;
        }
    }
    printf("\n");
}

void insert_at_the_beginning()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of the node \n");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    //empty list
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}


void insert_at_the_end()
{

    struct node *temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of the node \n");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    //empty list
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        p = start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = temp;
        temp->prev = p;
    }

}


void insert_after_a_node()
{
    int val;
    struct node *temp,*p;

    printf("Enter the value of node you want to insert the element after \n");
    scanf("%d",&val);

    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to insert \n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;

    p=start;
    while(p!=NULL)
    {
        if(p->data == val)
            break;

        p=p->next;
    }

    if(p==NULL)
        printf("%d is not in the list \n",val);
    else
    {
        temp->prev = p;
        temp->next = p->next;
        if(p->next!=NULL)
            p->next->prev=temp; // should not be done when p points to the last node because it will give an error
        p->next = temp;
    }
}


void insert_before_a_node()
{

    int val;
    struct node *temp,*p;

    printf("Enter the value of node you want to insert the element before \n");
    scanf("%d",&val);

    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element you want to insert \n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;


    if(val == start->data)
    {
        //if insert at 1st positon
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
    else
    {
       p = start;
       while(p!=NULL)
       {
           if(p->data == val)
            break;
            p = p->next;
       }
       if(p==NULL)
        printf("Element not found \n");
       else
       {
           temp->next = p;
           temp->prev = p->prev;
           p->prev->next = temp;
           p->prev = temp;
       }

    }
}


void delete_a_node()
{
    struct node *temp;
    int val;

    printf("Enter the element you want to delete \n");
    scanf("%d",&val);

    if(start == NULL)
        printf("Empty List \n");
    else
    {

        //only one node
        if(start->next == NULL)
        {
            if(start->data == val)
            {
                temp = start;
                free(temp);
                start = NULL;
            }
            else
                printf("Element not found \n");
        }

        //delete the 1st node
        else if(start->data == val)
        {
            temp = start;
            start = start->next;
            start->prev = NULL;
            free(temp);
        }
        else
        {
            //deleting a node in between
            temp = start->next;
            while(temp->next!=NULL)
            {
                if(temp->data == val)
                    break;
                temp = temp->next;
            }

            //node is in between
            if(temp->next!=NULL)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            else
            {
                //last node
                if(temp->data == val)
                {
                    temp->prev->next = NULL;
                    free(temp);
                }
                else
                    printf("Element not found \n");
            }
        }
    }

}

void reverse_a_list()
{
    struct node *p1, *p2;

    if(start == NULL)
        printf("Empty List \n");
    else
    {
        p1 = start;
        p2 = p1->next;
        p1->next = NULL;
        p1->prev = p2;

        while(p2!=NULL)
        {
            p2->prev = p2->next;
            p2->next = p1;
            p1=p2;
            p2 = p2->prev;
        }
        start = p1;
    }

}



int main()
{
    start = NULL;

    int choice;
    do
    {
        printf("Press 0 to exit \n");
        printf("Press 1  to insert elements  in the beginning of the linked list \nPress 2 to display elements from front of the linked list \nPress 3 to insert at the end \nPress 4 to insert after a particular node\n");
        printf("Press 5 to insert the node before an element \n");
        printf("Press 6 to delete a node \n");
        printf("Press 7 to reverse the list \n");

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
                display_from_front();
                break;
            case 3:
                insert_at_the_end();
                break;
            case 4:
                insert_after_a_node();
                break;
            case 5:
                insert_before_a_node();
                break;
            case 6:
                delete_a_node();
                break;
            case 7:
                reverse_a_list();
                break;
            default:
                printf("Please enter correct choice \n");
                break;
        }
    }while(choice != 0);
}



