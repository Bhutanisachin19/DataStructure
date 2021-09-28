//Single linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start;

// it is easy to insert node at the starting
void insert_at_the_beginning()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of the node \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(start == NULL)
    {
        //1st element
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }

}

void insert_at_the_end()
{
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of the node \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(start == NULL)
    {
        //1st element
        start = temp;
    }
    else
    {
        ptr = start;
        //traversing to the last element
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = NULL;//adding the last node
    }

}




void display()
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



void count_no_of_nodes()
{
    //same logic as traversal
    int num=0;
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
             num++;
            temp= temp->next;
        }
    }
    printf("Number of nodes in this linked list is %d \n",num);
}


void search_element()
{
    //same logic as traversal
    int num,pos=0;

    struct node *temp;
    if(start == NULL)
    {
        printf("EMPTY LIST \n");
    }
    else
    {
         printf("Enter the element to be searched \n");
         scanf("%d",&num);
         temp = start;
        while(temp!=NULL)
        {
            pos++;
            if(num == temp->data)
            {
                printf("ELEMENT FOUND at %d \n",pos);
                break;
            }
            temp = temp->next;
        }
        if(temp == NULL)
        {
            printf("ELEMENT NOT FOUND \n");
        }

    }
}



void insert_after_a_node()
{
    int val,flag = 0;
    printf("Enter the value after which this node is to be inserted ");
    scanf("%d",&val);

    struct node *temp1,*temp2;

    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node \n");
    scanf("%d",&temp2->data);

    temp1 = start;
    while(temp1!= NULL)
    {
        if(temp1->data == val)
        {
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    //because if we check using null , if the element is at the end next will be null
    if(flag ==0)
        printf("Element not found in list \n");
    else
    {
        temp2->next = temp1->next;
        temp1->next = temp2;
    }

}


void insert_before_a_node()
{

    int val,flag = 0;
    printf("Enter the value before which this node is to be inserted ");
    scanf("%d",&val);

    struct node *temp1,*temp2;

    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node \n");
    scanf("%d",&temp2->data);

    //1st position
    if(val == start->data)
    {
        temp2->next = start;
        start = temp2;
    }
    else
    {
        temp1 = start;
        while(temp1->next != NULL)
        {
            if(temp1->next->data == val)
            {
                flag = 1;
                break;
            }
            temp1 = temp1->next;
        }

        //because if we check using null , if the element is at the end next will be null
        if(flag ==0)
            printf("Element not found in list \n");
        else
        {
            temp2->next = temp1->next;
            temp1->next = temp2;
        }
    }
}

void insert_at_a_given_pos()
{

    int val;
    printf("Enter the position where you want to insert the node : ");
    scanf("%d",&val);

    struct node *temp1,*temp2;

    temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node \n");
    scanf("%d",&temp2->data);

    if(val == 1)
    {
        temp2->next = start;
        start = temp2;
    }
    else
    {
        int i;
        temp1 = start;
        for(i=1;i<val-1 && temp1!=NULL;i++)
        {
            temp1 = temp1->next;
        }

        if(temp1==NULL)
        {
            printf("You can insert only upto %dth position \n",i);
        }
        else
        {
            temp2->next = temp1->next;
            temp1->next = temp2;
        }
    }
}


void delete_a_node()
{
    int num;
    printf("Enter the number to be deleted \n");
    scanf("%d",&num);
    struct node *temp,*p;

    if(start == NULL)
        printf("Empty List \n");
    //1st node and only element
    else if(num == start->data && start->next==NULL)
    {
        temp = start;
        start = NULL;
        free(temp);
    }
    else if(num == start->data)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
    else
    {
        //deleting node in between or at the end
        p=start;
        while(p->next!=NULL)
        {
            if(p->next->data==num)
                break;
            p = p->next;
        }

        if(p->next==NULL)
            printf("Element %d not in the list \n", num);
        else
        {
            temp = p->next;
            p->next=temp->next;
            free(temp);
        }

    }
}


void reverse_list()
{
    struct node *prev,*aftr,*ptr;
    prev = NULL;
    ptr = start;

    while(ptr!=NULL)
    {
        aftr = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = aftr;
    }
    start = prev;

    printf("New list is \n");
    display();
}


void delete_list()
{
    //to delete complete list
    struct node *temp , *ptr;

    ptr = start;

    while(ptr)
    {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    start = NULL;

    printf("List deleted \n");
}


int main()
{
    start = NULL;

    int choice;
    do
    {
        printf("Press 0 to exit \n");
        printf("Press 1  to insert elements  in the beginning of the linked list \nPress 2 to display elements from linked list \nPress 3 to count the number of nodes \nPress 4 to search an element \n");
        printf("Press 5 to insert element at the end of the linked list \n");
        printf("Press 6 to insert element after a particular node of the linked list \n");
        printf("Press 7 to insert element before a particular node of the linked list \n");
        printf("Press 8 to insert element at a particular position in the linked list \n");
        printf("Press 9 to delete an element from the linked list \n");
        printf("Press 10 to reverse the linked list \n");
        printf("Press 11 to delete complete list \n");

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
                    count_no_of_nodes();
                    break;
            case 4:
                search_element();
                break;
            case 5:
                insert_at_the_end();
                break;
            case 6:
                insert_after_a_node();
                break;
            case 7:
                insert_before_a_node();
                break;
            case 8:
                insert_at_a_given_pos();
                break;
            case 9:
                delete_a_node();
                break;
            case 10:
                reverse_list();
                break;
            case 11:
                delete_list();
                break;
            default:
                printf("Please enter correct choice \n");
                break;
        }
    }while(choice != 0);
}
