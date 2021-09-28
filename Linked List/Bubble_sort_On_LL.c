/*

    Bubble sort on Linked list can be done in 2 ways
    1st sort by exchanging data(like in array)
    2nd sort by exchanging links

*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


struct node *insert_in_LL(struct node *start)
{
    //insert at the end
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

    return start;
}


void display(struct node *start)
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


void sort_by_exchanging_data(struct node *start)
{
    struct node *p ,*q,*end;
    int temp;

    for(end=NULL;end!=start->next;end=p)
    {
        for(p=start;p->next!=end;p=p->next)
        {
            q=p->next;
            if(p->data > q->data)
            {
                //swap
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

struct node *sort_by_exchanging_link(struct node *start)
{
    //r will point to the previous node of p
    struct node *p ,*q,*end,*r,*temp;

    for(end=NULL;end!=start->next;end=p)
    {
        for(r=p=start ; p->next!=end ; r=p ,p=p->next)
        {
            q=p->next;
            if(p->data > q->data)
            {
                //swap
                p->next = q->next;
                q->next=p;

                if(p!=start)
                    r->next=q;
                else
                    start=q;

                //swapping p and q pointers after swapping nodes
                temp=p;
                p=q;
                q=temp;
            }
        }
    }
    return start;
}


main()
{
    struct node *p1 = NULL , *p2=NULL;
    int i,num;

    printf("Enter the number of elements in the 1st linked list \n");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
       p1 = insert_in_LL(p1);
    }

    printf("List entered is \n");
    display(p1);

    printf("Sorted list \n");
    sort_by_exchanging_data(p1);
    display(p1);


    printf("For second list \n");


    printf("Enter the number of elements in the 2nd linked list \n");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
       p2 = insert_in_LL(p2);
    }

    printf("List entered is \n");
    display(p2);

    printf("Sorted list \n");
    p2 = sort_by_exchanging_link(p2);
    display(p2);



}













